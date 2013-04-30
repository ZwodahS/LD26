#include "../objects.h"
#include "../Game.h"
#include "../World.h"
#include <iostream>
RedBot::RedBot(Game* game)
    :AIBot(game)
{
    maxMove = 2;
    moveLeft = 2;
}

void RedBot::draw(Window* window, float delta)
{
    if(facingDirection == direction::North)
    {
        window->draw(_game->_assets.bots.red.up,_position.x,_position.y);
    }
    else if(facingDirection == direction::West)
    {
        window->draw(_game->_assets.bots.red.left,_position.x,_position.y);
    }
    else if(facingDirection == direction::East)
    {
        window->draw(_game->_assets.bots.red.right,_position.x,_position.y);
    }
    else if(facingDirection == direction::South)
    {
        window->draw(_game->_assets.bots.red.down,_position.x,_position.y);
    }

}

void RedBot::update(float delta)
{
    if(isMoving())
    {
        linearMove(delta);
    }
}

void RedBot::updateSight(World* world)
{
    if(world->canSeePlayer(_location.row,_location.col,6)) 
    {
        lastSeen = world->_player->getLocation();
        hasSeen = true;
    }
}
void RedBot::processAI(World* world)
{
    bool seen;
    if(world->canSeePlayer(_location.row,_location.col,9)) 
    {
        lastSeen = world->_player->getLocation();
        hasSeen = true;
        seen = true;
    }
    if(getLocation() == lastSeen)  //if arrive at location
    {
        hasSeen = false;
        seen = false;
    }
    
    if(seen && world->canSeePlayer(_location.row,_location.col,5))
    {
        world->attackPlayer(rand()%10 + 5, this);
    }
    else if(hasSeen)
    {
        moveTowardLastSeen(world);
    }
    else
    {
        randomMove();
    }
    moveLeft -= 1;
}
