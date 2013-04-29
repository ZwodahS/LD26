#include "../tiles.h"
#include "../Game.h"
#include "../consts.h"
#include "../Inventory.h"
#include <iostream>
ColorDoorTile::ColorDoorTile(Game* game,int color)
    :Tile(game)
{
    this->color = color;
    this->locked = true;
    this->type = Type_ColorDoorTile;
}

ColorDoorTile::~ColorDoorTile()
{
}

void ColorDoorTile::update(float delta)
{

}

void ColorDoorTile::draw(Window* window, float delta)
{
    if(locked)
    {
        if(color == doorcolor::RED)
        {
            window->draw(game->_assets.tiles.door.red,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
        }
        else if(color == doorcolor::GREEN)
        {
            window->draw(game->_assets.tiles.door.green,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
        }
        else if(color == doorcolor::BLUE)
        {
            window->draw(game->_assets.tiles.door.blue,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
        }
    }
    else
    {
        window->draw(game->_assets.tiles.floor,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
    }
    if(!visible)
    {
        if(seen)
        {
            window->draw(game->_assets.tiles.overlay.gray,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
        }
        else
        {
            window->draw(game->_assets.tiles.overlay.black,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
        }
    }

}
bool ColorDoorTile::isPassable()
{
    if(locked)
    {
        return false;
    }
    return true;
}

bool ColorDoorTile::requiresUnlock()
{
    if(locked)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool ColorDoorTile::unlock(Inventory* inventory)
{
    if(color == doorcolor::RED)
    {
        if(inventory->hasItemType(Type_Passive_DoorKey_RED))
        {
            locked = false;
            return true;
        }
        return false;
    }
    else if(color == doorcolor::BLUE)
    {
        if(inventory->hasItemType(Type_Passive_DoorKey_BLUE))
        {
            locked = false;
            return true;
        }
        return false;

    }
    else if(color == doorcolor::GREEN)
    {
        if(inventory->hasItemType(Type_Passive_DoorKey_GREEN))
        {
            locked = false;
            return true;
        }
        return false;

    }
    return false;
}
