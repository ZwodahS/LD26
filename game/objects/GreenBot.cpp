#include "../objects.h"
#include "../Game.h"
GreenBot::GreenBot(Game* game)
    :Bot(game)
{
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

}

