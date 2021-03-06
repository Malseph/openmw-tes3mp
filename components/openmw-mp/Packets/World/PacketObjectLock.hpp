#ifndef OPENMW_PACKETOBJECTLOCK_HPP
#define OPENMW_PACKETOBJECTLOCK_HPP

#include <components/openmw-mp/Packets/World/WorldPacket.hpp>

namespace mwmp
{
    class PacketObjectLock : public WorldPacket
    {
    public:
        PacketObjectLock(RakNet::RakPeerInterface *peer);

        virtual void Object(WorldObject &worldObject, bool send);
    };
}

#endif //OPENMW_PACKETOBJECTLOCK_HPP
