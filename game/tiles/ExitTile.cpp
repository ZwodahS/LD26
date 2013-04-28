#include "../tiles.h"
#include "../Game.h"
#include "../consts.h"
ExitTile::ExitTile(Game* game)
    :Tile(game)
{
    locked = true;
    type = Type_ExitTile;
}

ExitTile::~ExitTile()
{
}

void ExitTile::update(float delta)
{

}

void ExitTile::draw(Window* window, float delta)
{
    if(locked)
    {
        window->draw(game->_assets.tiles.exit_locked,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
    }
    else
    {
        window->draw(game->_assets.tiles.exit_open,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
    }
}

bool ExitTile::isPassable()
{
    return true;
}

