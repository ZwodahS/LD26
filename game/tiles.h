#ifndef _GAME_TILES_H_
#define _GAME_TILES_H_


#include "../framework/zf_framework.h"
class Game;
class Tile
{
        
    public:
        Tile(Game* game);
        ~Tile();
        virtual void update(float delta)=0;
        virtual void draw(Window* window, float delta)=0;
        Grid getGrid();
        void setGrid(int row, int col);
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

};

class WallTile : public Tile
{
    public:
        WallTile(Game* game);
        ~WallTile();
        void update(float delta);
        void draw(Window* window, float delta);
};

class ComputerTile : public Tile
{
    public:
        ComputerTile(Game* game);
        ~ComputerTile();
        void update(float delta);
        void draw(Window* window, float delta);
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
    protected:
        int color ; //0 for red , 1 for green , 2 for blue
};
class ExitTile : public Tile
{
    public:
        ExitTile(Game* game);
        ~ExitTile();
        void update(float delta);
        void draw(Window* window, float delta);
    protected:
        bool locked;
};
#endif
