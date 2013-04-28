#include "../items.h"
#include "../Game.h"

DoorKey::DoorKey(Game* game,int color)
    :Passive(Type_Passive_DoorKey,game)
{
    this->color = color;
}
DoorKey::~DoorKey()
{
}
void DoorKey::draw(Window* window, float delta, int x , int y)
{
    if(color == doorcolor::RED)
    {
        window->draw(_game->_assets.inventory.inventoryBG,x,y);
        window->draw(_game->_assets.inventory.redDoorCard,x,y);
    }
    else if(color == doorcolor::GREEN)
    {
        window->draw(_game->_assets.inventory.inventoryBG,x,y);
        window->draw(_game->_assets.inventory.blueDoorCard,x,y);
    }
    else if(color == doorcolor::BLUE)
    {
        window->draw(_game->_assets.inventory.inventoryBG,x,y);
        window->draw(_game->_assets.inventory.greenDoorCard,x,y);
    }
}
