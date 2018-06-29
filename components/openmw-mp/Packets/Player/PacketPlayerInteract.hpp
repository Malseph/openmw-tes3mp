#ifndef OPENMW_PACKETPLAYERINTERACT_HPP
#define OPENMW_PACKETPLAYERINTERACT_HPP

#include <components/openmw-mp/Packets/Player/PlayerPacket.hpp>

namespace mwmp
{
    class PacketPlayerInteract : public PlayerPacket
    {
    public:
        PacketPlayerInteract(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETPLAYERINTERACT_HPP
