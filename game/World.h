#ifndef _GAME_WORLD_H
#define _GAME_WORLD_H

#include "tiles.h"
#include "../framework/zf_framework.h"

#include <vector>
class Game;
class Bot;
class World
{
    public:
        World(Game* game);
        ~World();
        void initWorld(std::vector<std::vector<Tile*> > tiles);
        void initEnemies(int number);
        void draw(Window* window, float delta);
        Rectangle getDimension();
    private:
        std::vector<std::vector<Tile*> > _tiles;
        std::vector<Bot*> _enemyBots;
        Game* _game;

};
#endif
