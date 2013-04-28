#include "../objects.h"
#include "../World.h"
#include <stdlib.h>
#include "../../framework/zf_framework.h"
#include <iostream>
AIBot::AIBot(Game* game)
    :Bot(game)
{
    maxMove = 0;
    moveLeft = 0;
    hasSeen = false;
}


void AIBot::resetMoves()
{
    moveLeft = maxMove;
}

bool AIBot::stillHasMoves()
{
    return moveLeft > 0;
}

void AIBot::moveTowardLastSeen(World* world)
{
    Grid g = Grid(lastSeen.row - _location.row,lastSeen.col - _location.col);
    int random = rand() % 2;
    direction::Direction firstTry;
    direction::Direction secondTry;
    std::cout << "moving : " << g.row << " " << g.col << std::endl;
    if(random == 0) // try move in the longest distance first
    {
        if(abs(g.col) > abs(g.row))
        {
            if(g.col > 0)
            {
                firstTry = direction::East;    
            } 
            else
            {
                firstTry = direction::West;
            }
            if(g.row > 0)
            {
                secondTry = direction::South;
            }
            else
            {
                secondTry = direction::North;
            }
            
        }
        else
        {
            if(g.row > 0)
            {
                firstTry = direction::South;
            }
            else if(g.row < 0)
            {
                firstTry = direction::North;
            }
            if(g.col > 0)
            {
                secondTry = direction::East;    
            } 
            else
            {
                secondTry = direction::West;
            }
        }
    }
    else
    {
        if(abs(g.col) < abs(g.row))
        {
            if(g.col > 0)
            {
                firstTry = direction::East;    
            } 
            else
            {
                firstTry = direction::West;
            }
            if(g.row > 0)
            {
                secondTry = direction::South;
            }
            else
            {
                secondTry = direction::North;
            }
            
        }
        else
        {
            if(g.row > 0)
            {
                firstTry = direction::South;
            }
            else
            {
                firstTry = direction::North;
            }
            if(g.col > 0)
            {
                secondTry = direction::East;    
            } 
            else
            {
                secondTry = direction::West;
            }
        }
    }
    g = world->gridAt(_location,firstTry);
    bool canMove = world->canMoveTo(g); 
    if(canMove)
    {
        setLocation(g.row,g.col);
        faceTo(firstTry);
    }
    else
    {
        g = world->gridAt(_location,secondTry);
        canMove = world->canMoveTo(g);
        if(canMove)
        {
            setLocation(g.row,g.col);
            faceTo(secondTry);
        }
        else
        {
            randomMove();
        }
    }
}

void AIBot::randomMove()
{
        
}
