#include "../objects.h"
#include "../Game.h"
RedBot::RedBot(Game* game)
    :Bot(game)
{
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

}

