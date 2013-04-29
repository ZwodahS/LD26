#include "../items.h"
#include "../Game.h"

DoorKey::DoorKey(Game* game,int color)
    :Passive(Type_Passive_DoorKey_RED,game)
{
    this->color = color;
    if(color == doorcolor::RED)
    {
        _type = Type_Passive_DoorKey_RED;
    }
    else if(color == doorcolor::GREEN)
    {
        _type = Type_Passive_DoorKey_GREEN;
    }
    else if(color == doorcolor::BLUE)
    {
        _type = Type_Passive_DoorKey_BLUE;
    }
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
void DoorKey::drawInfo(Window* window, float delta, int x, int y)
{
    if(color == doorcolor::RED)
    {
        window->drawString("Red DoorKey ", _game->_assets.fonts.mono36,x+20,y+20);
        window->drawString("   Unlock Red doors.", _game->_assets.fonts.mono28,x+20,y+70);
    }
    else if(color == doorcolor::GREEN)
    {
        window->drawString("Green DoorKey ", _game->_assets.fonts.mono36,x+20,y+20);
        window->drawString("   Unlock Green doors.", _game->_assets.fonts.mono28,x+20,y+70);
    }
    else if(color == doorcolor::BLUE)
    {
        window->drawString("Blue DoorKey ", _game->_assets.fonts.mono36,x+20,y+20);
        window->drawString("   Unlock Blue doors.", _game->_assets.fonts.mono28,x+20,y+70);
    }
}
