#include "Inventory.h"
#include "consts.h"
Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::draw(Window* window, float delta,int selectedIndex)
{
    int row = 0;
    int col = 0;
    for(int i = 0 ; i < _items.size(); i++, col++)
    {
        _items[i]->draw(window, delta, col * gconsts::INV_SIZE + gconsts::INV_SPACE, row * gconsts::INV_SIZE + gconsts::INV_SPACE);
        if(i != 0 && i % 10 == 0)
        {
            row ++;
            col = 0;
        }
    }
}

void Inventory::addItem(Item* item)
{
    this->_items.push_back(item);
}
