#include "../tiles.h"
#include "../Game.h"
#include "../consts.h"
ColorDoorTile::ColorDoorTile(Game* game,int color)
    :Tile(game)
{
    this->color = color;
}

ColorDoorTile::~ColorDoorTile()
{
}

void ColorDoorTile::update(float delta)
{

}

void ColorDoorTile::draw(Window* window, float delta)
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

