#ifndef OPENMW_PROCESSORPLAYERINTERACT_HPP
#define OPENMW_PROCESSORPLAYERINTERACT_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerInteract : public PlayerProcessor
    {
    public:
        ProcessorPlayerInteract()
        {
            BPP_INIT(ID_PLAYER_INTERACT)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            bool sneaking = ((player.movementFlags & 8) == 8); //8 is sneaking movement flag

            Script::Call<Script::CallbackIdentity("OnPlayerInteract")>(player.getId(), Players::getPlayer(player.interactTarget)->getId(), sneaking);
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERINTERACT_HPP
