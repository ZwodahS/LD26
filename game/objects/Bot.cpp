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

//return true if still alive
bool Bot::damage(int amount)
{
    currentHp -= amount;
    return currentHp > 0;
}
