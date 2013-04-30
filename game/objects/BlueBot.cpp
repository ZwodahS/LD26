#include "../objects.h"
#include "../Game.h"
#include "../World.h"
BlueBot::BlueBot(Game* game)
    :AIBot(game)
{
    maxMove = 2;
    moveLeft = 2;
}

void BlueBot::draw(Window* window, float delta)
{
    if(facingDirection == direction::North)
    {
        window->draw(_game->_assets.bots.blue.up,_position.x,_position.y);
    }
    else if(facingDirection == direction::West)
    {
        window->draw(_game->_assets.bots.blue.left,_position.x,_position.y);
    }
    else if(facingDirection == direction::East)
    {
        window->draw(_game->_assets.bots.blue.right,_position.x,_position.y);
    }
    else if(facingDirection == direction::South)
    {
        window->draw(_game->_assets.bots.blue.down,_position.x,_position.y);
    }

}

void BlueBot::update(float delta)
{
    if(isMoving())
    {
        linearMove(delta);
    }
}

void BlueBot::updateSight(World* world)
{
    if(world->canSeePlayer(_location.row,_location.col,6)) 
    {
        lastSeen = world->_player->getLocation();
        hasSeen = true;
    }
}
void BlueBot::processAI(World* world)
{
    bool seen;
    if(world->canSeePlayer(_location.row,_location.col,6)) 
    {
        lastSeen = world->_player->getLocation();
        hasSeen = true;
        seen = true;
    }
    if(getLocation() == lastSeen)
    {
        hasSeen = false;
        seen = false;
    }    
    if(seen && world->canSeePlayer(_location.row,_location.col,3))
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
