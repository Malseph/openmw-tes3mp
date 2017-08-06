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

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Script::Call<Script::CallbackIdentity("OnPlayerDynamicRecord")>(player.getId());
        }
    };
}


#endif //OPENMW_PROCESSORPLAYERDYNAMICRECORD_HPP
