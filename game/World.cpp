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
    for(int i = 0 ; i < _enemyBots.size() ; i++)
    {
        delete _enemyBots[i];
    }
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
            if(_tiles[r][c]->type == Type_ComputerTile)
            {
                computerGrid = Grid(r,c);
                computerTile = (ComputerTile*)_tiles[r][c];
            }
            else if(_tiles[r][c]->type == Type_ExitTile)
            {
                exitGrid = Grid(r,c);
                exitTile = (ExitTile*)_tiles[r][c];
            }
        }
    }
}
bool World::doNextAI()
{
    for(int i = 0 ; i < _enemyBots.size() ; i++)
    {
        if(_enemyBots[i]->stillHasMoves())
        {
            _enemyBots[i]->processAI(this);
            return true;
        }
    }
    return false;
}
void World::initEnemies(int number)
{
    for(int i = 0 ; i < number ; i ++)
    {
        spawnEnemy();
    }
}
AIBot* randomBot(Game* game)
{
    int r = rand() % 3;
    if(r == 0)
    {
        return new RedBot(game);
    }
    else if(r == 1)
    {
        return new BlueBot(game);
    }
    else
    {
        return new GreenBot(game);
    }

}
void World::spawnEnemy()
{
    Grid g = findAEmptySpot();
    AIBot* bot = randomBot(_game);
    bot->setLocation(g.row,g.col);
    bot->alignPosition();
    _enemyBots.push_back(bot);
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

void World::update(float delta)
{
    _player->update(delta);
    for(int i = 0 ; i < _enemyBots.size() ; i++)
    {
        _enemyBots[i]->update(delta);
    }

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
        if(tileAt(_enemyBots[i]->getLocation())->visible)
        {
            _enemyBots[i]->draw(window,delta);
        }
    }
    _player->draw(window,delta);
}

void drawSelection(Window* window,Grid grid, bool selectable)
{

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
    if(canMoveTo(target))
    {
        return true;    
    }
    else
    {
        return false;
    }

}

bool World::hasBot(int row, int col)
{
    for(int i = 0 ; i < _enemyBots.size() ; i++)
    {
        if(_enemyBots[i]->getLocation() == Grid(row,col))
        {
            return true;
        }
    }
    if(_player->getLocation() == Grid(row, col))
    {
        return true;
    }
    return false;
}

bool World::unlock(PlayerBot* bot,int x , int y)
{
    Grid g = bot->getLocation();
    Grid target = Grid(g.row+y , g.col+x);
    if(target.row < 0 || target.col < 0 || target.col >= _tiles[0].size() || target.row >= _tiles.size())
    {
        return false;
    }
    if(_tiles[target.row][target.col]->requiresUnlock())
    {
        return _tiles[target.row][target.col]->unlock(bot->inventory);
    }
    return false;
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
// return if this bot can see the player from this row / col
bool World::canSeePlayer(int row , int col, int vision)
{
    clearTilesVisited();
    std::vector<Tile*> cachedTiles = std::vector<Tile*>(0);
    cachedTiles.push_back(_tiles[row][col]);
    _tiles[row][col]->visitedValue = vision;
    _tiles[row][col]->visited = true;

    for(int i = 0 ; i < cachedTiles.size() ; i++)
    {
        Grid g = cachedTiles[i]->getGrid();
        if(!cachedTiles[i]->isPassable() || cachedTiles[i]->visitedValue == 0 ) // not passable then ignore it.
        {
            continue;
        }
        if(g.row == _player->getLocation().row && g.col == _player->getLocation().col)
        {
            return true;
        }
        if(inRange(g.row + 1, g.col) && !_tiles[g.row+1][g.col]->visited)
        {
            _tiles[g.row+1][g.col]->visitedValue = cachedTiles[i]->visitedValue - 1;
            _tiles[g.row+1][g.col]->visited = true;
            cachedTiles.push_back(_tiles[g.row+1][g.col]);
        }
        if(inRange(g.row - 1, g.col) && !_tiles[g.row-1][g.col]->visited)
        {
            _tiles[g.row-1][g.col]->visitedValue = cachedTiles[i]->visitedValue - 1;
            _tiles[g.row-1][g.col]->visited = true;
            cachedTiles.push_back(_tiles[g.row-1][g.col]);
        }
        if(inRange(g.row,g.col+1) && !_tiles[g.row][g.col+1]->visited)
        {
            _tiles[g.row][g.col+1]->visitedValue = cachedTiles[i]->visitedValue - 1;
            _tiles[g.row][g.col+1]->visited = true;
            cachedTiles.push_back(_tiles[g.row][g.col+1]);
        }
        if(inRange(g.row,g.col-1) && !_tiles[g.row][g.col-1]->visited)
        {
            _tiles[g.row][g.col-1]->visitedValue = cachedTiles[i]->visitedValue - 1;
            _tiles[g.row][g.col-1]->visited = true;
            cachedTiles.push_back(_tiles[g.row][g.col-1]);
        }
    }
    return false;
}

void World::vision(int row , int col , int vision)
{
    clearTilesVision();
    std::vector<Tile*> cachedTiles = std::vector<Tile*>(0);
    cachedTiles.push_back(_tiles[row][col]);
    _tiles[row][col]->visitedValue = vision;
    _tiles[row][col]->visited = true;
    _tiles[row][col]->show();

    for(int i = 0 ; i < cachedTiles.size() ; i++)
    {
        Grid g = cachedTiles[i]->getGrid();
        if(!cachedTiles[i]->isPassable() || cachedTiles[i]->visitedValue == 0 ) // not passable then ignore it.
        {
            continue;
        }
        if(inRange(g.row + 1, g.col) && !_tiles[g.row+1][g.col]->visited)
        {
            _tiles[g.row+1][g.col]->visitedValue = cachedTiles[i]->visitedValue - 1;
            _tiles[g.row+1][g.col]->visited = true;
            _tiles[g.row+1][g.col]->show();
            cachedTiles.push_back(_tiles[g.row+1][g.col]);
        }
        if(inRange(g.row - 1, g.col) && !_tiles[g.row-1][g.col]->visited)
        {
            _tiles[g.row-1][g.col]->visitedValue = cachedTiles[i]->visitedValue - 1;
            _tiles[g.row-1][g.col]->visited = true;
            _tiles[g.row-1][g.col]->show();
            cachedTiles.push_back(_tiles[g.row-1][g.col]);
        }
        if(inRange(g.row,g.col+1) && !_tiles[g.row][g.col+1]->visited)
        {
            _tiles[g.row][g.col+1]->visitedValue = cachedTiles[i]->visitedValue - 1;
            _tiles[g.row][g.col+1]->visited = true;
            _tiles[g.row][g.col+1]->show();
            cachedTiles.push_back(_tiles[g.row][g.col+1]);
        }
        if(inRange(g.row,g.col-1) && !_tiles[g.row][g.col-1]->visited)
        {
            _tiles[g.row][g.col-1]->visitedValue = cachedTiles[i]->visitedValue - 1;
            _tiles[g.row][g.col-1]->visited = true;
            _tiles[g.row][g.col-1]->show();
            cachedTiles.push_back(_tiles[g.row][g.col-1]);
        }
    }

}
void World::clearTilesVision()
{
    for(int r = 0 ; r < _tiles.size() ; r ++)
    {
        for(int c = 0 ; c < _tiles[r].size() ; c++)
        {
            _tiles[r][c]->visited = false;
            _tiles[r][c]->visitedValue = 0;
            _tiles[r][c]->visible = false;
        }
    }
}
void World::clearTilesVisited()
{
    for(int r = 0 ; r < _tiles.size() ; r ++)
    {
        for(int c = 0 ; c < _tiles[r].size() ; c++)
        {
            _tiles[r][c]->visited = false;
            _tiles[r][c]->visitedValue = 0;
        }
    }
}


void World::attackPlayer(int damage, Bot* attackBot)
{
    _player->damage(damage);
}

Grid World::gridAt(Grid g, direction::Direction d)
{
    if(d == direction::North)
    {
        return Grid(g.row-1,g.col);
    }
    else if(d == direction::South)
    {
        return Grid(g.row+1,g.col);
    }
    else if(d == direction::East)
    {
        return Grid(g.row,g.col+1);
    }
    else
    {
        return Grid(g.row,g.col-1);
    }
}

bool World::canMoveTo(Grid g)
{
    if(inRange(g.row,g.col))
    {
        if(_tiles[g.row][g.col]->isPassable())
        {
            if(hasBot(g.row,g.col))
            {
                return false;
            }
            return true;
        }
        return false;
    }
    return false;
}

void World::resetEnemyMoves()
{
    for(int i = 0 ; i < _enemyBots.size() ; i++)
    {
        _enemyBots[i]->resetMoves();
    }
}
Tile* World::tileAt(Grid g)
{
    if(inRange(g.row,g.col))
    {
        return _tiles[g.row][g.col];
    }
    return NULL;
}

void World::playerEnteredTile(PlayerBot* player)
{
    Grid g = player->getLocation();
    if(g == exitGrid)
    {
        // do nothing for now
    }
    else if (g == computerGrid)
    {
        unlockExit();
    }

}

void World::unlockExit()
{
    exitTile->unlockExit();
}

void World::drawSelection(Window* window, Grid grid, bool selectable)
{

}
