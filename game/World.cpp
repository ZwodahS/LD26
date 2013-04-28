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
        spawnEnemy();
    }
}

void World::spawnEnemy()
{
    Grid g = findAEmptySpot();
}


Grid World::findAEmptySpot()
{
    int row = rand() % _tiles.size();
    int col = rand() % _tiles[row].size();
    while(!_tiles[row][col]->isPassable())
    {
        int rdiff = (rand() % 5 ) - 3;
        int cdiff = (rand() % 5 ) - 3;
        if(inRange(row+rdiff,col+cdiff))
        {
            row = row + rdiff;
            col = col + cdiff; 
        }
    }
    return Grid(row,col);
}

void World::initPlayer(PlayerBot* player)
{
    this->_player = player;
    // TODO : find the starting location.
    Grid g = findAEmptySpot();
    _player->setLocation(g.row,g.col);
    _player->alignPosition();
}
void World::draw(Window* window , float delta,int startRow,int endRow,int startCol,int endCol)
{
    for(int r = startRow ; r < (_tiles.size()<endRow?_tiles.size():endRow) ; r++)
    {
        for(int c = startCol ; c < (_tiles[r].size()<endCol?_tiles[r].size():endCol) ; c++)
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

bool World::inRange(int row, int col)
{
    if(row < 0 || row >= _tiles.size() || col < 0 || col >= _tiles[row].size())
    {
        return false;
    }
    return true;
}
