#include "../items.h"
#include "../Game.h"

Item::Item(ItemType type,Game* game)
{
    this->_type = type;
    this->_game = game;
}

Item::~Item()
{
}

int Item::getCount()
{
    return 1;
}

bool Item::equippable()
{
    return false;
}
