#include "../items.h"
#include "../Game.h"

Resource::Resource(ItemType type,Game* game,int count)
    :Item(type,game)
{
    this->count = count;
}

Resource::~Resource()
{
}

int Resource::getCount()
{
    return count;
}
