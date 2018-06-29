#include "container.hpp"

#include <MyGUI_InputManager.h>
#include <MyGUI_Button.h>

/*
    Start of tes3mp addition

    Include additional headers for multiplayer purposes
*/
#include <components/openmw-mp/Log.hpp>
#include "../mwmp/Main.hpp"
#include "../mwmp/Networking.hpp"
#include "../mwmp/WorldEvent.hpp"
#include "../mwmp/CellController.hpp"
/*
    End of tes3mp addition
*/

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/dialoguemanager.hpp"
#include "../mwbase/mechanicsmanager.hpp"

#include "../mwworld/class.hpp"
#include "../mwworld/inventorystore.hpp"

#include "../mwmechanics/creaturestats.hpp"

#include "countdialog.hpp"
#include "inventorywindow.hpp"

#include "itemview.hpp"
#include "itemwidget.hpp"
#include "inventoryitemmodel.hpp"
#include "containeritemmodel.hpp"
#include "sortfilteritemmodel.hpp"
#include "pickpocketitemmodel.hpp"
#include "draganddrop.hpp"

namespace MWGui
{

    ContainerWindow::ContainerWindow(DragAndDrop* dragAndDrop)
        : WindowBase("openmw_container_window.layout")
        , mDragAndDrop(dragAndDrop)
        , mSortModel(NULL)
        , mModel(NULL)
        , mSelectedItem(-1)
    {
        getWidget(mDisposeCorpseButton, "DisposeCorpseButton");
        getWidget(mTakeButton, "TakeButton");
        getWidget(mCloseButton, "CloseButton");

        getWidget(mItemView, "ItemView");
        mItemView->eventBackgroundClicked += MyGUI::newDelegate(this, &ContainerWindow::onBackgroundSelected);
        mItemView->eventItemClicked += MyGUI::newDelegate(this, &ContainerWindow::onItemSelected);

        mDisposeCorpseButton->eventMouseButtonClick += MyGUI::newDelegate(this, &ContainerWindow::onDisposeCorpseButtonClicked);
        mCloseButton->eventMouseButtonClick += MyGUI::newDelegate(this, &ContainerWindow::onCloseButtonClicked);
        mTakeButton->eventMouseButtonClick += MyGUI::newDelegate(this, &ContainerWindow::onTakeAllButtonClicked);

        setCoord(200,0,600,300);
    }

    void ContainerWindow::onItemSelected(int index)
    {
        if (mDragAndDrop->mIsOnDragAndDrop && mModel)
        {
            dropItem();
            return;
        }

        const ItemStack& item = mSortModel->getItem(index);

        // We can't take a conjured item from a container (some NPC we're pickpocketing, a box, etc)
        if (item.mFlags & ItemStack::Flag_Bound)
        {
            MWBase::Environment::get().getWindowManager()->messageBox("#{sContentsMessage1}");
            return;
        }

        MWWorld::Ptr object = item.mBase;
        int count = item.mCount;
        bool shift = MyGUI::InputManager::getInstance().isShiftPressed();
        if (MyGUI::InputManager::getInstance().isControlPressed())
            count = 1;

        mSelectedItem = mSortModel->mapToSource(index);

        if (count > 1 && !shift)
        {
            CountDialog* dialog = MWBase::Environment::get().getWindowManager()->getCountDialog();
            dialog->openCountDialog(object.getClass().getName(object), "#{sTake}", count);
            dialog->eventOkClicked.clear();
            dialog->eventOkClicked += MyGUI::newDelegate(this, &ContainerWindow::dragItem);
        }
        else
            dragItem (NULL, count);
    }

    void ContainerWindow::dragItem(MyGUI::Widget* sender, int count)
    {
        if (!onTakeItem(mModel->getItem(mSelectedItem), count))
            return;

        /*
            Start of tes3mp addition

            Send an ID_CONTAINER packet every time an item starts being dragged
            from a container
        */
        mwmp::WorldEvent *worldEvent = mwmp::Main::get().getNetworking()->getWorldEvent();
        worldEvent->reset();
        worldEvent->cell = *mPtr.getCell()->getCell();
        worldEvent->action = mwmp::BaseEvent::REMOVE;

        mwmp::WorldObject worldObject;
        worldObject.refId = mPtr.getCellRef().getRefId();
        worldObject.refNumIndex = mPtr.getCellRef().getRefNum().mIndex;
        worldObject.mpNum = mPtr.getCellRef().getMpNum();

        MWWorld::Ptr itemPtr = mModel->getItem(mSelectedItem).mBase;

        mwmp::ContainerItem containerItem;
        containerItem.refId =itemPtr.getCellRef().getRefId();
        containerItem.count = itemPtr.getRefData().getCount();
        containerItem.charge = itemPtr.getCellRef().getCharge();
        containerItem.enchantmentCharge = itemPtr.getCellRef().getEnchantmentCharge();
        containerItem.soul = itemPtr.getCellRef().getSoul();
        containerItem.actionCount = count;

        worldObject.containerItems.push_back(containerItem);
        worldEvent->addObject(worldObject);

        mwmp::Main::get().getNetworking()->getWorldPacket(ID_CONTAINER)->setEvent(worldEvent);
        mwmp::Main::get().getNetworking()->getWorldPacket(ID_CONTAINER)->Send();

        LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Sending ID_CONTAINER about\n- Ptr cellRef: %s, %i\n- cell: %s\n- item: %s, %i",
                           worldObject.refId.c_str(), worldObject.refNumIndex, worldEvent->cell.getDescription().c_str(),
                           containerItem.refId.c_str(), containerItem.count);
        /*
            End of tes3mp addition
        */

        mDragAndDrop->startDrag(mSelectedItem, mSortModel, mModel, mItemView, count);
    }

    void ContainerWindow::dropItem()
    {
        bool success = mModel->onDropItem(mDragAndDrop->mItem.mBase, mDragAndDrop->mDraggedCount);

        /*
            Start of tes3mp addition

            Send an ID_CONTAINER packet every time an item is dropped in a container
        */
        if (success)
        {
            mwmp::WorldEvent *worldEvent = mwmp::Main::get().getNetworking()->getWorldEvent();
            worldEvent->reset();
            worldEvent->cell = *mPtr.getCell()->getCell();
            worldEvent->action = mwmp::BaseEvent::ADD;

            mwmp::WorldObject worldObject;
            worldObject.refId = mPtr.getCellRef().getRefId();
            worldObject.refNumIndex = mPtr.getCellRef().getRefNum().mIndex;
            worldObject.mpNum = mPtr.getCellRef().getMpNum();

            MWWorld::Ptr itemPtr = mDragAndDrop->mItem.mBase;

            mwmp::ContainerItem containerItem;
            containerItem.refId = itemPtr.getCellRef().getRefId();
            
            // Make sure we get the drag and drop count, not the count of the original item
            containerItem.count = mDragAndDrop->mDraggedCount;

            containerItem.charge = itemPtr.getCellRef().getCharge();
            containerItem.enchantmentCharge = itemPtr.getCellRef().getEnchantmentCharge();
            containerItem.soul = itemPtr.getCellRef().getSoul();

            worldObject.containerItems.push_back(containerItem);
            worldEvent->addObject(worldObject);

            mwmp::Main::get().getNetworking()->getWorldPacket(ID_CONTAINER)->setEvent(worldEvent);
            mwmp::Main::get().getNetworking()->getWorldPacket(ID_CONTAINER)->Send();

            LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Sending ID_CONTAINER about\n- Ptr cellRef: %s, %i\n- cell: %s\n- item: %s, %i",
                               worldObject.refId.c_str(), worldObject.refNumIndex, worldEvent->cell.getDescription().c_str(),
                               containerItem.refId.c_str(), containerItem.count);
        }
        /*
            End of tes3mp addition
        */

        if (success)
            mDragAndDrop->drop(mModel, mItemView);
    }

    void ContainerWindow::onBackgroundSelected()
    {
        if (mDragAndDrop->mIsOnDragAndDrop && mModel)
            dropItem();
    }

    void ContainerWindow::setPtr(const MWWorld::Ptr& container)
    {
        /*
            Start of tes3mp addition

            Mark this container as open for multiplayer logic purposes
        */
        mwmp::Main::get().getCellController()->openContainer(container);
        /*
            End of tes3mp addition
        */

        mPtr = container;

        bool loot = mPtr.getClass().isActor() && mPtr.getClass().getCreatureStats(mPtr).isDead();

        if (mPtr.getClass().hasInventoryStore(mPtr))
        {
            if (mPtr.getClass().isNpc() && !loot)
            {
                // we are stealing stuff
                mModel = new PickpocketItemModel(mPtr, new InventoryItemModel(container),
                                                 !mPtr.getClass().getCreatureStats(mPtr).getKnockedDown());
            }
            else
                mModel = new InventoryItemModel(container);
        }
        else
        {
            mModel = new ContainerItemModel(container);
        }

        mDisposeCorpseButton->setVisible(loot);

        mSortModel = new SortFilterItemModel(mModel);

        mItemView->setModel (mSortModel);
        mItemView->resetScrollBars();

        MWBase::Environment::get().getWindowManager()->setKeyFocusWidget(mCloseButton);

        setTitle(container.getClass().getName(container));
    }

    void ContainerWindow::resetReference()
    {
        ReferenceInterface::resetReference();
        mItemView->setModel(NULL);
        mModel = NULL;
        mSortModel = NULL;
    }

    void ContainerWindow::onClose()
    {
        /*
            Start of tes3mp addition

            Mark this container as closed for multiplayer logic purposes
        */
        mwmp::Main::get().getCellController()->closeContainer(mPtr);
        /*
            End of tes3mp addition
        */

        WindowBase::onClose();

        if (mModel)
            mModel->onClose();
    }

    void ContainerWindow::onCloseButtonClicked(MyGUI::Widget* _sender)
    {
        MWBase::Environment::get().getWindowManager()->removeGuiMode(GM_Container);
    }

    void ContainerWindow::onTakeAllButtonClicked(MyGUI::Widget* _sender)
    {
        if(mDragAndDrop != NULL && mDragAndDrop->mIsOnDragAndDrop)
            return;

        // transfer everything into the player's inventory
        ItemModel* playerModel = MWBase::Environment::get().getWindowManager()->getInventoryWindow()->getModel();
        mModel->update();

        // unequip all items to avoid unequipping/reequipping
        if (mPtr.getClass().hasInventoryStore(mPtr))
        {
            MWWorld::InventoryStore& invStore = mPtr.getClass().getInventoryStore(mPtr);
            for (size_t i=0; i<mModel->getItemCount(); ++i)
            {
                const ItemStack& item = mModel->getItem(i);
                if (invStore.isEquipped(item.mBase) == false)
                    continue;

                invStore.unequipItem(item.mBase, mPtr);
            }
        }

        mModel->update();

        for (size_t i=0; i<mModel->getItemCount(); ++i)
        {
            if (i==0)
            {
                // play the sound of the first object
                MWWorld::Ptr item = mModel->getItem(i).mBase;
                std::string sound = item.getClass().getUpSoundId(item);
                MWBase::Environment::get().getWindowManager()->playSound(sound);
            }

            const ItemStack& item = mModel->getItem(i);

            if (!onTakeItem(item, item.mCount))
                break;

            mModel->moveItem(item, item.mCount, playerModel);
        }

        MWBase::Environment::get().getWindowManager()->removeGuiMode(GM_Container);

        /*
            Start of tes3mp addition

            Send an ID_CONTAINER packet every time the Take All button is used on
            a container
        */
        mwmp::WorldEvent *worldEvent = mwmp::Main::get().getNetworking()->getWorldEvent();
        worldEvent->reset();
        worldEvent->cell = *mPtr.getCell()->getCell();
        worldEvent->action = mwmp::BaseEvent::SET;

        mwmp::WorldObject worldObject;
        worldObject.refId = mPtr.getCellRef().getRefId();
        worldObject.refNumIndex = mPtr.getCellRef().getRefNum().mIndex;
        worldObject.mpNum = mPtr.getCellRef().getMpNum();
        worldEvent->addObject(worldObject);

        mwmp::Main::get().getNetworking()->getWorldPacket(ID_CONTAINER)->setEvent(worldEvent);
        mwmp::Main::get().getNetworking()->getWorldPacket(ID_CONTAINER)->Send();

        LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Sending ID_CONTAINER about\n- Ptr cellRef: %s, %i\n- cell: %s",
                           worldObject.refId.c_str(), worldObject.refNumIndex, worldEvent->cell.getDescription().c_str());
        /*
            End of tes3mp addition
        */
    }

    void ContainerWindow::onDisposeCorpseButtonClicked(MyGUI::Widget *sender)
    {
        if(mDragAndDrop == NULL || !mDragAndDrop->mIsOnDragAndDrop)
        {
            onTakeAllButtonClicked(mTakeButton);

            /*
                Start of tes3mp addition

                Send an ID_OBJECT_DELETE packet every time a corpse is disposed of
            */
            if (!mPtr.getClass().isPersistent(mPtr))
            {
                mwmp::WorldEvent *worldEvent = mwmp::Main::get().getNetworking()->getWorldEvent();
                worldEvent->reset();
                worldEvent->addObjectDelete(mPtr);
                worldEvent->sendObjectDelete();
            }
            /*
                End of tes3mp addition
            */

            if (mPtr.getClass().isPersistent(mPtr))
                MWBase::Environment::get().getWindowManager()->messageBox("#{sDisposeCorpseFail}");
            else
                MWBase::Environment::get().getWorld()->deleteObject(mPtr);

            mPtr = MWWorld::Ptr();
        }
    }

    void ContainerWindow::onReferenceUnavailable()
    {
        MWBase::Environment::get().getWindowManager()->removeGuiMode(GM_Container);
    }

    bool ContainerWindow::onTakeItem(const ItemStack &item, int count)
    {
        return mModel->onTakeItem(item.mBase, count);
    }

}
