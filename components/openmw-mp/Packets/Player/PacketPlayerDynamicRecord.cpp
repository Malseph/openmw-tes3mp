#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketPlayerDynamicRecord.hpp"

using namespace std;
using namespace mwmp;

PacketPlayerDynamicRecord::PacketPlayerDynamicRecord(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_DYNAMICRECORD;
}

void PacketPlayerDynamicRecord::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    RW(player->dynamicRecordChanges.action, send);

    if (send)
        player->dynamicRecordChanges.count = (unsigned int) (player->dynamicRecordChanges.records.size());
    else
        player->dynamicRecordChanges.records.clear();

    RW(player->dynamicRecordChanges.count, send);

    for (unsigned int i = 0; i < player->dynamicRecordChanges.count; i++)
    {
        DynamicRecord record;

        if (send)
            record = player->dynamicRecordChanges.records.at(i);

        RW(record.refId, send, 1);
        RW(record.type, send, 1);

        if(record.type == DynamicRecord::SPELL)
        {
            record.spell.mId = record.refId;
            RW(record.spell.mName, send, 1);

            RW(record.spell.mData.mCost, send, 1);
            RW(record.spell.mData.mFlags, send, 1);
            RW(record.spell.mData.mType, send, 1);

            int effectCount;
            if(send)
                effectCount = record.spell.mEffects.mList.size();

            RW(effectCount, send, 1);

            for (unsigned int j = 0; j < effectCount; j++)
            {
                ESM::ENAMstruct effect;
                if(send)
                    effect = record.spell.mEffects.mList.at(j);

                RW(effect.mArea, send, 1);
                RW(effect.mAttribute, send, 1);
                RW(effect.mDuration, send, 1);
                RW(effect.mEffectID, send, 1);
                RW(effect.mMagnMax, send, 1);
                RW(effect.mMagnMin, send, 1);
                RW(effect.mRange, send, 1);
                RW(effect.mSkill, send, 1);

                if(!send)
                    record.spell.mEffects.mList.push_back(effect);
            }
        }

        if(record.type == DynamicRecord::POTION)
        {
            record.potion.mId = record.refId;
            RW(record.potion.mName, send, 1);
            RW(record.potion.mModel, send, 1);
            RW(record.potion.mIcon, send, 1);
            RW(record.potion.mScript, send, 1);

            RW(record.potion.mData.mWeight, send, 1);
            RW(record.potion.mData.mValue, send, 1);
            RW(record.potion.mData.mAutoCalc, send, 1);

            int effectCount;
            if(send)
                effectCount = record.potion.mEffects.mList.size();

            RW(effectCount, send, 1);

            for (unsigned int j = 0; j < effectCount; j++)
            {
                ESM::ENAMstruct effect;
                if(send)
                    effect = record.potion.mEffects.mList.at(j);

                RW(effect.mArea, send, 1);
                RW(effect.mAttribute, send, 1);
                RW(effect.mDuration, send, 1);
                RW(effect.mEffectID, send, 1);
                RW(effect.mMagnMax, send, 1);
                RW(effect.mMagnMin, send, 1);
                RW(effect.mRange, send, 1);
                RW(effect.mSkill, send, 1);

                if(!send)
                    record.potion.mEffects.mList.push_back(effect);
            }
        }

        if(record.type == DynamicRecord::ENCHANTMENT)
        {
            record.enchantment.mId = record.refId;

            RW(record.enchantment.mData.mCost, send, 1);
            RW(record.enchantment.mData.mAutocalc, send, 1);
            RW(record.enchantment.mData.mCharge, send, 1);
            RW(record.enchantment.mData.mType, send, 1);

            RW(record.enchantmentContext.gemCharge, send, 1);
            RW(record.enchantmentContext.newItemName, send, 1);
            RW(record.enchantmentContext.newItemRefId, send, 1);
            RW(record.enchantmentContext.oldItemRefId, send, 1);
            RW(record.enchantmentContext.itemType, send, 1);

            RW(record.enchantmentContext.oldItemRefId, send, 1);
            RW(record.enchantmentContext.newItemName, send, 1);
            RW(record.enchantmentContext.gemCharge, send, 1);

            int effectCount;
            if(send)
                effectCount = record.enchantment.mEffects.mList.size();

            RW(effectCount, send, 1);

            for (unsigned int j = 0; j < effectCount; j++)
            {
                ESM::ENAMstruct effect;
                if(send)
                    effect = record.enchantment.mEffects.mList.at(j);

                RW(effect.mArea, send, 1);
                RW(effect.mAttribute, send, 1);
                RW(effect.mDuration, send, 1);
                RW(effect.mEffectID, send, 1);
                RW(effect.mMagnMax, send, 1);
                RW(effect.mMagnMin, send, 1);
                RW(effect.mRange, send, 1);
                RW(effect.mSkill, send, 1);

                if(!send)
                    record.enchantment.mEffects.mList.push_back(effect);
            }
        }

        if (!send)
            player->dynamicRecordChanges.records.push_back(record);
    }
}
