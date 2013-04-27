#ifndef _GAME_TILES_H_
#define _GAME_TILES_H_


#include "../framework/zf_framework.h"
class Game;
class Tile
{
        
    public:
        Tile(Game* game);
        ~Tile();
        virtual void update(float delta);
        virtual void draw(Window* window, float delta);
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


#endif
