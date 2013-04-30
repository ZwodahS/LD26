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
    AITurn = false;
    weapon = NULL;
}

WorldScreen::~WorldScreen()
{
}

void WorldScreen::init(Display* display, Window* parent)
{
    assignedWindow = parent->createCameraWindow(world->getDimension(),Rectangle(288,288,64,64));
    world->vision(_player->getLocation().row,_player->getLocation().col,_player->getSight());
}

bool WorldScreen::update(InputManager* inputs, float delta)
{
    assignedWindow->focusTo(_player->getCurrentPosition(),delta*1000);
    if(world->isAnimating())
    {
        world->update(delta);
        return true;
    }
    else if(AITurn)
    {
        if(!world->doNextAI())
        {
            AITurn = false;
            newTurn();
        }    
    }
    else 
    {
        if(_player->getActionPoints() == 0)
        {
            endTurn();
        }
        else if(weapon != NULL)
        {
            if(inputs->fire.thisPressed)
            {
                fireWeapon();
            }
            else if(inputs->up.thisPressed)
            {
                selectedGrid.row-=1;
            }
            else if(inputs->down.thisPressed)
            {
                selectedGrid.row+=1;
            }
            else if(inputs->left.thisPressed)
            {
                selectedGrid.col-=1;
            }
            else if(inputs->right.thisPressed)
            {
                selectedGrid.col+=1;
            }
            else if(inputs->select.thisPressed)
            {
            }
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
            else if(inputs->fire.thisPressed)
            {
                fireWeapon();
            }
            if(!(x==0 && y==0))
            {
                if(_player->canMove())
                {
                    if(world->moveBot(_player,x,y))
                    {
                        _player->moved();
                        world->vision(_player->getLocation().row,_player->getLocation().col,_player->getSight());
                        world->playerEnteredTile(_player);
                    }
                    else if(world->unlock(_player,x,y))
                    {
                        _player->moved();
                        world->vision(_player->getLocation().row,_player->getLocation().col,_player->getSight());
                    }
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
    }
    return true;
}

void WorldScreen::fireWeapon()
{
    if(weapon==NULL)
    {
        if(_player->equippedWeapon != NULL )
        {
            if(_player->equippedWeapon->getActionCost() > weapon->getActionCost())
            {
                weapon = _player->equippedWeapon;
                selectedGrid = _player->getLocation();
            }
        }
    }
    else
    {
        weapon = NULL;
    }
}

void WorldScreen::draw(float delta)
{
    int startRow = assignedWindow->visibleRowStarts(gconsts::TILE_SIZE);
    int startCol = assignedWindow->visibleColStarts(gconsts::TILE_SIZE);
    world->draw(assignedWindow,delta,startRow,startRow+assignedWindow->numberOfVisibleRows(gconsts::TILE_SIZE),startCol,startCol+assignedWindow->numberOfVisibleCols(gconsts::TILE_SIZE));
    if(weapon != NULL)
    {
        world->drawSelection(assignedWindow,selectedGrid,weapon->canFireAt(world,_player->getLocation(),selectedGrid));
    }
    assignedWindow->finalize();

}

void WorldScreen::endTurn()
{
    AITurn = true;
}

void WorldScreen::newTurn()
{
    _player->resetPoints();
    world->resetEnemyMoves();
}
