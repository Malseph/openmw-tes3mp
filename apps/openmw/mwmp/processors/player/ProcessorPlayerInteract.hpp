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

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            // Placeholder to be filled in later
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERINTERACT_HPP
