#include "../items.h"
#include "../Game.h"

Ammo::Ammo(ItemType type,Game* game,int count)
    :Resource(type,game,count)
{
}

Ammo::~Ammo()
{
}
