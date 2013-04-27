#include "../tiles.h"
#include "../Game.h"
#include "../consts.h"
ComputerTile::ComputerTile(Game* game)
    :Tile(game)
{
}

ComputerTile::~ComputerTile()
{
}

void ComputerTile::update(float delta)
{

}

void ComputerTile::draw(Window* window, float delta)
{
    window->draw(game->_assets.tiles.computer,grid.col*gconsts::TILE_SIZE,grid.row*gconsts::TILE_SIZE);
}

