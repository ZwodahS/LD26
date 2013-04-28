#include "../tiles.h"
#include "../consts.h"
#include "../Game.h"
FloorTile::FloorTile(Game* game)
    :Tile(game)
{
    type = Type_FloorTile;
}

FloorTile::~FloorTile()
{
}

void FloorTile::update(float delta)
{

}

void FloorTile::draw(Window* window, float delta)
{
    window->draw(game->_assets.tiles.floor,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
}

bool FloorTile::isPassable()
{
    return true;
}
