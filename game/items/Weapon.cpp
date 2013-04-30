#include "../items.h"

Weapon::Weapon(ItemType type, Game* game)
    :Equipment(type,game)
{
    equipped = false;
}

Weapon::~Weapon()
{
}

bool Weapon::equippable()
{
    return true;
}
