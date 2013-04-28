#include "../objects.h"
#include "../Game.h"
#include "../consts.h"
#include <iostream>
MapObject::MapObject(Game* game)
{
    this->_game = game;
    _location.row = 0;
    _location.col = 0;
    _position.x = 0;
    _position.y = 0;
    _moveSpeed = 100;
}

void MapObject::setLocation(int row , int col)
{
    _location.row = row;
    _location.col = col;
}

void MapObject::moveLocation(int rowDiff , int colDiff)
{
    setLocation(_location.row + rowDiff, _location.col + colDiff);
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

bool MapObject::isMoving()
{
    return getCurrentPosition() != getTargetPosition();
}

Point2 MapObject::getCurrentPosition()
{
    return _position;
}

Point2 MapObject::getTargetPosition()
{
    return Point2(_location.col*gconsts::TILE_SIZE , _location.row*gconsts::TILE_SIZE);
}

Grid MapObject::getLocation()
{
    return _location;
}
void MapObject::linearMove(float delta)
{
    int moveAmount = delta * _moveSpeed;
    Point2 target = getTargetPosition();
    Point2 current = getCurrentPosition();

    Point2 movement = target - current; // treat point2 like a vector
    if(movement.x > 0)
    {
        int destX = current.x + moveAmount;
        _position.x = destX > target.x ? target.x : destX;
    }
    else if(movement.x < 0)
    {
        int destX = current.x - moveAmount;
        _position.x = destX < target.x ? target.x : destX;
    }
    

    if(movement.y > 0)
    {
        int destY = current.y + moveAmount;
        _position.y = destY > target.y ? target.y : destY;
    }
    else if(movement.y < 0)
    {
        int destY = current.y - moveAmount;
        _position.y = destY < target.y ? target.y : destY;
    }
    //move the x
    //move the y
}
