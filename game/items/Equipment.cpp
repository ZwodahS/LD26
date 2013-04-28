#include "../items.h"
#include "../Game.h"

Equipment::Equipment(ItemType type,Game* game)
    :Item(type,game)
{
}

Equipment::~Equipment()
{
}
