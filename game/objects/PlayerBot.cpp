#include "../objects.h"
#include "../Game.h"
#include "../Inventory.h"
#include <iostream>
PlayerBot::PlayerBot(Game* game)
    :Bot(game)
{
    inventory = new Inventory(game);
    inventory->addItem(new SmallAmmo(game,3));
    inventory->addItem(new BombAmmo(game,3));
    inventory->addItem(new ScrapMetal(game, 3));
    inventory->addItem(new Wrench(game));
    inventory->addItem(new SmallGun(game));
    inventory->addItem(new BombLauncher(game));
    inventory->addItem(new DoorKey(game,0));
    inventory->addItem(new DoorKey(game,1));
    inventory->addItem(new DoorKey(game,2));
    
    maxPoint = 4;
    pointLeft = 4;
}

void PlayerBot::draw(Window* window, float delta)
{
    if(facingDirection == direction::North)
    {
        window->draw(_game->_assets.bots.player.up,_position.x,_position.y);
    }
    else if(facingDirection == direction::West)
    {
        window->draw(_game->_assets.bots.player.left,_position.x,_position.y);
    }
    else if(facingDirection == direction::East)
    {
        window->draw(_game->_assets.bots.player.right,_position.x,_position.y);
    }
    else if(facingDirection == direction::South)
    {
        window->draw(_game->_assets.bots.player.down,_position.x,_position.y);
    }
}

void PlayerBot::update(float delta)
{
    if(isMoving())
    {
        linearMove(delta);
    }
}

int PlayerBot::getActionPoints()
{
    return pointLeft;
}

int PlayerBot::getMaxPoints()
{
    return maxPoint;
}
void PlayerBot::resetPoints()
{
    pointLeft = getMaxPoints();
}

int PlayerBot::getMoveCost()
{
    return 1;
}

void PlayerBot::moved()
{
    pointLeft -= getMoveCost();
    pointLeft = pointLeft < 0 ? 0 : pointLeft;
}

int PlayerBot::getSight()
{
    return 10;
}

bool PlayerBot::canMove()
{
    return getMoveCost() <= getActionPoints();
}
