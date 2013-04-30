#include "../objects.h"
#include "../Game.h"
#include "../World.h"
GreenBot::GreenBot(Game* game)
    :AIBot(game)
{
    moveLeft = 4;
    maxMove = 4;
}

void GreenBot::draw(Window* window, float delta)
{
    if(facingDirection == direction::North)
    {
        window->draw(_game->_assets.bots.green.up,_position.x,_position.y);
    }
    else if(facingDirection == direction::West)
    {
        window->draw(_game->_assets.bots.green.left,_position.x,_position.y);
    }
    else if(facingDirection == direction::East)
    {
        window->draw(_game->_assets.bots.green.right,_position.x,_position.y);
    }
    else if(facingDirection == direction::South)
    {
        window->draw(_game->_assets.bots.green.down,_position.x,_position.y);
    }

}

void GreenBot::update(float delta)
{
    if(isMoving())
    {
        linearMove(delta);
    }
    
}

void GreenBot::updateSight(World* world)
{
    if(world->canSeePlayer(_location.row,_location.col,10)) 
    {
        lastSeen = world->_player->getLocation();
        hasSeen = true;
    }
}
void GreenBot::processAI(World* world)
{
    bool seen;
    if(world->canSeePlayer(_location.row,_location.col,10)) 
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
    if(seen && world->canSeePlayer(_location.row,_location.col,2))
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
