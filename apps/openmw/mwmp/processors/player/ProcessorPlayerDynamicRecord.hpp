#ifndef OPENMW_PROCESSORPLAYERDYNAMICRECORD_HPP
#define OPENMW_PROCESSORPLAYERDYNAMICRECORD_HPP


#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerDynamicRecord : public PlayerProcessor
    {
    public:
        ProcessorPlayerDynamicRecord()
        {
            BPP_INIT(ID_PLAYER_DYNAMICRECORD)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            if (!isRequest())
            {
                LocalPlayer &localPlayer = static_cast<LocalPlayer&>(*player);

                int dynamicRecordAction = localPlayer.dynamicRecordChanges.action;

                localPlayer.addDynamicRecords();
            }
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERDYNAMICRECORD_HPP
