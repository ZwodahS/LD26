#include "../screen.h"
#include "../Game.h"
#include "../objects.h"
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
    if(world->isAnimating())
    {
        _player->update(delta);
        return true;
    }
    else if(moveMade >= _player->getMaxMove())
    {
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
            if(world->moveBot(_player,x,y))
            {
            }
        }
    }
    return true;
}

void WorldScreen::draw(float delta)
{
    world->draw(assignedWindow,delta);
    assignedWindow->finalize();
}

