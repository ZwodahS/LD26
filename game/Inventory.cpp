#include "Inventory.h"
#include "consts.h"
#include "Game.h"
Inventory::Inventory(Game* game)
{
    this->game = game;
    selection_offset = 0;
    multiplier = 1;
}

Inventory::~Inventory()
{
}

void Inventory::draw(Window* window, float delta,int selectedIndex)
{
    int row = 0;
    int col = 0;
    selection_offset += multiplier* delta * 10;
    if(multiplier == 1 && selection_offset > 4)
    {
        multiplier = -1;
    }
    else if(multiplier == -1 && selection_offset < -4)
    {
        multiplier = 1;
    }
    for(int i = 0 ; i < _items.size(); i++, col++)
    {
        if(i != 0 && i % 10 == 0)
        {
            row ++;
            col = 0;
        }
        _items[i]->draw(window, delta, col * (gconsts::INV_SIZE + gconsts::INV_SPACE), row * (gconsts::INV_SIZE + gconsts::INV_SPACE));
        if(i == selectedIndex)
        {
            drawSelection(window,delta,col * (gconsts::INV_SIZE + gconsts::INV_SPACE), row * (gconsts::INV_SIZE + gconsts::INV_SPACE),(int)selection_offset,40);
        }
    }
    info(window,delta,_items[selectedIndex],selectedIndex>50?0:1);
}

void Inventory::addItem(Item* item)
{
    this->_items.push_back(item);
}

void Inventory::drawSelection(Window* window, float delta, int x , int y,int offset, int selection_width)
{
    window->draw(game->_assets.selection.NW,x-(int)offset,y-(int)offset);
    window->draw(game->_assets.selection.NE,x+selection_width+(int)offset,y-(int)offset);
    window->draw(game->_assets.selection.SE,x+selection_width+(int)offset,y+selection_width+(int)offset);
    window->draw(game->_assets.selection.SW,x-(int)offset,y+selection_width+(int)offset);
}

// 0 = put it at top
// 1 = put it at bottom
void Inventory::info(Window* window, float delta , Item* item, int location) 
{
    window->draw(game->_assets.others.inventoryBackground,0,270*location); 
}
