#include "../items.h"
#include "../Game.h"
SmallGun::SmallGun(Game* game)
    :Weapon(Type_Equipment_SmallArm,game)
{

}

SmallGun::~SmallGun()
{
}
void SmallGun::draw(Window* window, float delta, int x , int y)
{
    window->draw(_game->_assets.inventory.inventoryBG,x,y);
    window->draw(_game->_assets.inventory.smallGun,x,y);
}
void SmallGun::drawInfo(Window* window, float delta, int x, int y)
{
    window->drawString("Small Gun", _game->_assets.fonts.mono36,x+20,y+20);
    window->drawString("   Uses Small Ammo. Deals damage to enemy", _game->_assets.fonts.mono28,x+20,y+70);
}

bool SmallGun::canFireAt(World* world, Grid playerLocation, Grid targetLocation)
{
    return true;
}

int SmallGun::getActionCost()
{
    return 1;
}
