#include "../tiles.h"
#include "../consts.h"
#include "../Game.h"
WallTile::WallTile(Game* game)
    :Tile(game)
{
    type = Type_WallTile;
}

WallTile::~WallTile()
{
}

void WallTile::update(float delta)
{

}

void WallTile::draw(Window* window, float delta)
{
    window->draw(game->_assets.tiles.wall,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
}

bool WallTile::isPassable()
{
    return false;
}
