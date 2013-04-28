#include "../tiles.h"
#include <iostream>
Tile::Tile(Game* game)
{
    this->game = game;
    this->type = Type_Tile;
    this->visited = false;
    this->visitedValue = 0;
    this->visible = false;
    this->seen = false;
}

Tile::~Tile()
{
}

void Tile::setGrid(int row, int col)
{
    grid.row = row;
    grid.col = col;
}

Grid Tile::getGrid()
{
    return grid;
}

void Tile::show()
{
    visible = true;
    seen = true;
}
