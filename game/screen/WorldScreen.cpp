#include "../screen.h"
#include "../Game.h"
#include "../objects.h"
#include "../consts.h"
#include "../../framework/zf_framework.h"
#include <iostream>

WorldScreen::WorldScreen(Game* game,World* world,PlayerBot* player)
    :Screen(game)
{
    this->world = world;
    this->_player=player;
    moveMade = 0;
}

WorldScreen::~WorldScreen()
{
}

void WorldScreen::init(Display* display, Window* parent)
{
    assignedWindow = parent->createCameraWindow(world->getDimension(),Rectangle(288,288,64,64));
}

bool WorldScreen::update(InputManager* inputs, float delta)
{
    assignedWindow->focusTo(_player->getCurrentPosition(),delta*1000);
    if(world->isAnimating())
    {
        _player->update(delta);
        return true;
    }
    else 
    {
        int x = 0;
        int y = 0;
        if(inputs->up.thisPressed)
        {
            x = 0;
            y = -1;
            _player->faceTo(direction::North);
        }
        else if(inputs->down.thisPressed)
        {
            x = 0 ; 
            y = 1;
            _player->faceTo(direction::South);
        }
        else if(inputs->left.thisPressed)
        {
            x = -1;
            y = 0;
            _player->faceTo(direction::West);
        }
        else if(inputs->right.thisPressed)
        {
            x = 1;
            y = 0;
            _player->faceTo(direction::East);
        }
        if(!(x==0 && y==0))
        {
            if(_player->getMoveCost()<=_player->getActionPoints() && world->moveBot(_player,x,y))
            {
                _player->moved();
            }
        }
        else
        {
            if(inputs->select.thisPressed)
            {
                endTurn();
            }
        }
    }
    return true;
}

void WorldScreen::draw(float delta)
{
    int startRow = assignedWindow->visibleRowStarts(gconsts::TILE_SIZE);
    int startCol = assignedWindow->visibleColStarts(gconsts::TILE_SIZE);
    world->draw(assignedWindow,delta,startRow,startRow+assignedWindow->numberOfVisibleRows(gconsts::TILE_SIZE),startCol,startCol+assignedWindow->numberOfVisibleCols(gconsts::TILE_SIZE));
    assignedWindow->finalize();
}

void WorldScreen::endTurn()
{
    newTurn();
}

void WorldScreen::newTurn()
{
    _player->resetPoints();
}
