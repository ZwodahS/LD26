#include "../objects.h"
#include "../Game.h"
#include <iostream>
PlayerBot::PlayerBot(Game* game)
    :Bot(game)
{
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

}
