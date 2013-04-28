#include "World.h"
#include "Game.h"
#include "consts.h"
#include "objects.h"
#include <iostream>
World::World(Game* game)
{
    this->_game = game;
}

World::~World()
{
}

void World::initWorld(std::vector<std::vector<Tile*> > tiles)
{
    this->_tiles = std::vector<std::vector<Tile*> >(tiles.size(),std::vector<Tile*>(tiles[0].size(),NULL));
    for(int r = 0 ; r < _tiles.size() ; r++)
    {
        for(int c = 0 ; c < _tiles[r].size() ; c++)
        {
            _tiles[r][c] = tiles[r][c];
            _tiles[r][c]->setGrid(r,c);
        }
    }
}

void World::initEnemies(int number)
{
    for(int i = 0 ; i < number ; i ++)
    {
        int x = rand() % 4;
        if(x == 0)
        {
            _enemyBots.push_back(new RedBot(_game));
        }
        else if(x == 1)
        {
            _enemyBots.push_back(new BlueBot(_game));
        }
        else if(x == 2)
        {
            _enemyBots.push_back(new GreenBot(_game));
        }
        else if(x == 3)
        {
            _enemyBots.push_back(new PlayerBot(_game));
        }
    }
    for(int i = 0 ; i < number ; i++)
    {
        _enemyBots[i]->setLocation(i,i);
        _enemyBots[i]->alignPosition();
    }
}

void World::draw(Window* window , float delta)
{
    for(int r = 0 ; r < _tiles.size() ; r++)
    {
        for(int c = 0 ; c < _tiles[r].size() ; c++)
        {
            _tiles[r][c]->draw(window,delta);
        }
    }
    for(int i = 0 ; i < _enemyBots.size() ; i++)
    {
        _enemyBots[i]->draw(window,delta);
    }
}

Rectangle World::getDimension()
{
    return Rectangle(0,0,_tiles[0].size() * gconsts::TILE_SIZE,_tiles.size() * gconsts::TILE_SIZE);
}
