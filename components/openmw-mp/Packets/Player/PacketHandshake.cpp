//
// Created by koncord on 28.04.16.
//

#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketHandshake.hpp"

using namespace mwmp;

PacketHandshake::PacketHandshake(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_HANDSHAKE;
    orderChannel = CHANNEL_SYSTEM;
}

void PacketHandshake::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);
    RW(player->npc.mName, send);
    RW(player->passw, send);
}
