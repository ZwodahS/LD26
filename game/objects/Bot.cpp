#include "../objects.h"
#include "../consts.h"
Bot::Bot(Game* game)
    :MapObject(game)
{
    faceTo(direction::North);
}

void Bot::faceTo(direction::Direction d)
{
    this->facingDirection = d;
}

