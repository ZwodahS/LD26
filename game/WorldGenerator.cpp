#include "Game.h"
#include <stdlib.h>
std::vector<std::vector<Tile*> > Game::generateWorld(int row, int col)
{
    std::vector<std::vector<Tile*> > tiles = std::vector<std::vector<Tile*> >(row,std::vector<Tile*>(col,NULL));
    for(int r = 0 ; r < row ; r++)
    {
        for(int c = 0 ; c < col ; c++)
        {
            int x = rand() % 7;
            if(x == 0)
            {
                tiles[r][c] = new WallTile(this);
            }
            else if(x == 1)
            {
                tiles[r][c] = new ComputerTile(this);
            }
            else if(x == 2)
            {
                tiles[r][c] = new ColorDoorTile(this,doorcolor::RED);
            }
            else if(x == 3)
            {
                tiles[r][c] = new ColorDoorTile(this,doorcolor::GREEN);
            }
            else if(x == 4)
            {
                tiles[r][c] = new ColorDoorTile(this,doorcolor::BLUE);
            }
            else if(x == 5)
            {
                tiles[r][c] = new ExitTile(this);
            }
            else
            {
                tiles[r][c] = new FloorTile(this);
            }
        }
    }
    return tiles;
}
