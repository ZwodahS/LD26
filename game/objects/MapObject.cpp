#include "../objects.h"
#include "../Game.h"
#include "../consts.h"
MapObject::MapObject(Game* game)
{
    this->_game = game;
    _location.row = 0;
    _location.col = 0;
    _position.x = 0;
    _position.y = 0;
}

void MapObject::setLocation(int row , int col)
{
    _location.row = row;
    _location.col = col;
}

void MapObject::setPosition(int x , int y)
{
    _position.x = x;
    _position.y = y;
}
void MapObject::alignPosition()
{
    _position.x = _location.col * gconsts::TILE_SIZE;
    _position.y = _location.row * gconsts::TILE_SIZE;
}
