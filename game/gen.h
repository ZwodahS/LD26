#ifndef _GAME_GEN_H_
#define _GAME_GEN_H_
#include "tiles.h"
#include <vector>
class Room
{
    public:
        Room(Game* game ,std::vector<std::vector<char> > roomTemplate);
        ~Room();

        std::vector<std::vector<Tile*> > generateTile(int rotation);
        Tile* getTile(int row , int col , int rotation);
        Tile* getTile(int row , int col);
    private:
        Game* _game;
        std::vector<std::vector<char> > _template; // template is assumed to be square.
};
#endif
