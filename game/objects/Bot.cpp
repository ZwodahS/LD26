#include "../objects.h"
#include "../consts.h"
Bot::Bot(Game* game)
    :MapObject(game)
{
    faceTo(direction::North);
    currentHp = 100;
    maxHp = 100;
}

void Bot::faceTo(direction::Direction d)
{
    this->facingDirection = d;
}

int Bot::getCurrentHp()
{
    return currentHp;
}

int Bot::getMaxHp()
{
    return maxHp;
}
