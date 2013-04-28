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
}

void World::initPlayer(PlayerBot* player)
{
    this->_player = player;
    // TODO : find the starting location.
    for(int r = 0 ; r < _tiles.size() ; r++)
    {
        for(int c = 0 ; c < _tiles.size() ; c++)
        {
            if(_tiles[r][c]->isPassable())
            {
                _player->setLocation(r,c);
                _player->alignPosition();
                return;
            }
        }
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
    _player->draw(window,delta);
}

Rectangle World::getDimension()
{
    return Rectangle(0,0,_tiles[0].size() * gconsts::TILE_SIZE,_tiles.size() * gconsts::TILE_SIZE);
}

bool World::isAnimating()
{
    if(_player->isMoving())
    {
        return true;
    }
    for(int i = 0 ; i < _enemyBots.size() ; i++)
    {
        if(_enemyBots[i]->isMoving())
        {
            return true;
        }
    }
    return false;
}

bool World::canMove(Bot* bot , int x , int y) // no diagonal movement. Current assumption is that |x| + |y| = 1
{
    Grid g = bot->getLocation();
    Grid target = Grid(g.row+y , g.col+x);
    if(target.row < 0 || target.col < 0 || target.col >= _tiles[0].size() || target.row >= _tiles.size())
    {
        return false;
    }
    if(_tiles[target.row][target.col]->isPassable())
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool World::moveBot(Bot* bot, int x, int y)
{
    if(canMove(bot,x,y))
    {
        bot->moveLocation(y,x);
        return true;
    }
    return false;
}
