#include "Game.h"
#include "gen.h"
#include <fstream>
#include <stdlib.h>
#include "../framework/zf_helper.h"
#include <iostream>
#define ROOM_SIZE 5
void Game::initRooms()
{
    _templateRooms = std::vector<Room*>(0, NULL);    
    _priorityRooms = std::vector<Room*>(0, NULL);    

    loadRoom("assets/rooms/01.r");
    loadRoom("assets/rooms/02.r");
    loadRoom("assets/rooms/03.r");
    loadRoom("assets/rooms/04.r");
    loadRoom("assets/rooms/05.r");
    loadRoom("assets/rooms/06.r");
    loadRoom("assets/rooms/07.r");
    loadRoom("assets/rooms/08.r");
    loadRoom("assets/rooms/09.r");
}

void Game::loadRoom(const std::string roomFile)
{
    std::string line;
    std::ifstream file;
    file.open(roomFile.c_str());
    std::vector<std::vector<char> > _template = std::vector<std::vector<char> >(ROOM_SIZE,std::vector<char>(5,'1')) ;
    bool priority = false;
    int roomCount = 1;
    if(file.is_open() && file.good())
    {
        getline(file,line);
        if(line[0] == 'P') // prority
        {
            priority = true; 
        }
        else 
        {
            int value = 1;
            toInt(line,value);
            roomCount = value;
        }
        for(int r = 0 ; r < ROOM_SIZE ; r++)
        {
            if(!file.good())
            {
                return;
            }
            getline(file,line);
            for(int c = 0 ; c < ROOM_SIZE ; c++)
            {
                _template[r][c] = line[c];
            }
        }
    }
    if(priority)
    {
        _priorityRooms.push_back(new Room(this,_template));
    }
    else
    {
        for(int i = 0 ; i < roomCount ; i ++)
        {
            _templateRooms.push_back(new Room(this,_template));
        }
    }
}
std::vector<std::vector<Tile*> > Game::generateWorld(int row, int col)
{
    std::vector<std::vector<Tile*> > tiles = std::vector<std::vector<Tile*> >(row*ROOM_SIZE,std::vector<Tile*>(col*ROOM_SIZE,NULL));
    for(int r = 0 ; r < row ; r++)
    {
        for(int c = 0 ; c < col ; c++)
        {
            //randomly get a template room
            Room* room = _templateRooms[rand() % _templateRooms.size()];
            std::vector<std::vector<Tile*> > roomTiles = room->generateTile(rand()%4);
            for(int innerR = 0 ; innerR < ROOM_SIZE ; innerR ++)
            {
                for(int innerC = 0 ; innerC < ROOM_SIZE ; innerC ++)
                {
                    tiles[innerR + (r*ROOM_SIZE)][innerC + (c*ROOM_SIZE)] = roomTiles[innerR][innerC];
                }
            }
        }
    }
    return tiles;
}
