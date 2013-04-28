#ifndef _GAME_WORLD_H
#define _GAME_WORLD_H

#include "tiles.h"
#include "../framework/zf_framework.h"

#include <vector>
class Game;
class Bot;
class AIBot;
class PlayerBot;
class World
{
    public:
        World(Game* game);
        ~World();
        void initWorld(std::vector<std::vector<Tile*> > tiles);
        void initEnemies(int number);
        void initPlayer(PlayerBot* player);
        void update(float delta);
        void draw(Window* window, float delta,int startRow, int endRow,int startCol ,int endCol);
        bool isAnimating(); // return false if any of the bots are moving.
        Rectangle getDimension();


        bool canMove(Bot* bot, int x , int y);
        bool moveBot(Bot* bot, int x , int y);
        
        void spawnEnemy();
        Grid findAEmptySpot();
        bool inRange(int row, int col);


        bool canSeePlayer(int row ,int col,int vision);
        PlayerBot* _player;

        void attackPlayer(int damage,Bot* attackingBot);


        Grid gridAt(Grid g, direction::Direction d);
        bool canMoveTo(Grid g);

        bool doNextAI();
        void resetEnemyMoves();
    private:
        std::vector<std::vector<Tile*> > _tiles;
        std::vector<AIBot*> _enemyBots;

        Game* _game;
        
        void clearTilesVisited();
};
#endif
