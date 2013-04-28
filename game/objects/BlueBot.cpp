#include "../objects.h"
#include "../Game.h"
BlueBot::BlueBot(Game* game)
    :Bot(game)
{
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

}

