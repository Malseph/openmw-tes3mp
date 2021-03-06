#ifndef OPENMW_PACKETCONSOLECOMMAND_HPP
#define OPENMW_PACKETCONSOLECOMMAND_HPP

#include <components/openmw-mp/Packets/World/WorldPacket.hpp>

namespace mwmp
{
    class PacketConsoleCommand : public WorldPacket
    {
    public:
        PacketConsoleCommand(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *bs, bool send);
    };
}

#endif //OPENMW_PACKETCONSOLECOMMAND_HPP
