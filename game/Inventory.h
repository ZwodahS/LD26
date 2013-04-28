#ifndef _GAME_INVENTORY_H_
#define _GAME_INVENTORY_H_

#include "items.h"
#include "../framework/zf_framework.h"

class Inventory
{
    
    public:
        Inventory();
        ~Inventory();

        void draw(Window* window, float delta,int selectedIndex);
        
        std::vector<Item*> _items;

        void addItem(Item* item);
};


#endif
