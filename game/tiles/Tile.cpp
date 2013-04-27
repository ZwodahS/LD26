#include "../tiles.h"
#include <iostream>
Tile::Tile(Game* game)
{
    this->game = game;
}

Tile::~Tile()
{
}

void Tile::setGrid(int row, int col)
{
    grid.row = row;
    grid.col = col;
}

void Tile::update(float delta)
{
}
void Tile::draw(Window* window, float delta)
{
}
