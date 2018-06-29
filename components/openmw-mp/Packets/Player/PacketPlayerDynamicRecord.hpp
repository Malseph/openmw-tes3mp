#ifndef OPENMW_PACKETPLAYERDYNAMICRECORD_HPP
#define OPENMW_PACKETPLAYERDYNAMICRECORD_HPP

#include <components/openmw-mp/Packets/Player/PlayerPacket.hpp>

namespace mwmp
{
    class PacketPlayerDynamicRecord : public PlayerPacket
    {
    public:
        PacketPlayerDynamicRecord(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETPLAYERDYNAMICRECORD_HPP
