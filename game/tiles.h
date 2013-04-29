#ifndef _GAME_TILES_H_
#define _GAME_TILES_H_


#include "../framework/zf_framework.h"

enum TileType
{
    Type_Tile = 0,
    Type_FloorTile,
    Type_WallTile,
    Type_ComputerTile,
    Type_ColorDoorTile,
    Type_ExitTile,

};
class Game;
class Inventory;
class Tile
{
    public:
        Tile(Game* game);
        ~Tile();
        virtual void update(float delta)=0;
        virtual void draw(Window* window, float delta)=0;
        Grid getGrid();
        void setGrid(int row, int col);
        virtual bool isPassable()=0;
        virtual bool requiresUnlock();
        virtual bool unlock(Inventory* inventory);
        TileType type;
        bool visible;
        bool seen;
        // using in vision tracing
        bool visited; 
        int visitedValue;

        void show();
    protected:
        Grid grid;
        Game* game;
};

class FloorTile : public Tile
{
    public:
        FloorTile(Game* game);
        ~FloorTile();
        void update(float delta);
        void draw(Window* window , float delta);
        bool isPassable();

};

class WallTile : public Tile
{
    public:
        WallTile(Game* game);
        ~WallTile();
        void update(float delta);
        void draw(Window* window, float delta);
        bool isPassable();
};

class ComputerTile : public Tile
{
    public:
        ComputerTile(Game* game);
        ~ComputerTile();
        void update(float delta);
        void draw(Window* window, float delta);
        bool isPassable();
};

namespace doorcolor
{
    const int RED = 0;
    const int GREEN = 1;
    const int BLUE = 2;
}
class ColorDoorTile : public Tile
{
    public:
        ColorDoorTile(Game* game,int color);
        ~ColorDoorTile();
        void update(float delta);
        void draw(Window* window, float delta);
        bool isPassable();
        bool requiresUnlock();
        bool unlock(Inventory* inventory);
    protected:
        int color ; //0 for red , 1 for green , 2 for blue
        bool locked;
};
class ExitTile : public Tile
{
    public:
        ExitTile(Game* game);
        ~ExitTile();
        void update(float delta);
        void draw(Window* window, float delta);
        bool isPassable();
        void unlockExit();
    protected:
        bool locked;
};
#endif
