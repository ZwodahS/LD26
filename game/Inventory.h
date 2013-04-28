#ifndef _GAME_INVENTORY_H_
#define _GAME_INVENTORY_H_

#include "items.h"
#include "../framework/zf_framework.h"
class Game;
class Inventory
{
    
    public:
        Inventory(Game* game);
        ~Inventory();

        void draw(Window* window, float delta,int selectedIndex);
        
        std::vector<Item*> _items;

        void addItem(Item* item);
    private:
        Game* game;
        float selection_offset;
        float multiplier;
        void drawSelection(Window* window, float delta, int x , int y,int offset, int selection_width); // the location is the top left.
        
};


#endif
