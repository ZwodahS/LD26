#include "Game.h"
std::vector<std::vector<Tile*> > Game::generateWorld(int row, int col)
{
    std::vector<std::vector<Tile*> > tiles = std::vector<std::vector<Tile*> >(row,std::vector<Tile*>(col,NULL));
    for(int r = 0 ; r < row ; r++)
    {
        for(int c = 0 ; c < col ; c++)
        {
            tiles[r][c] = new FloorTile(this);
        }
    }
    return tiles;
}
