#include "../items.h"
#include "../Game.h"
SmallAmmo::SmallAmmo(Game* game,int count)
    :Ammo(Type_Resource_Ammo_Small,game,count)
{
    
}
SmallAmmo::~SmallAmmo()
{
}
void SmallAmmo::draw(Window* window, float delta, int x , int y)
{
    window->draw(_game->_assets.inventory.inventoryBG,x,y);
    window->draw(_game->_assets.inventory.smallAmmo,x,y);
}
void SmallAmmo::drawInfo(Window* window, float delta, int x, int y)
{
    window->drawString("Small Ammo", _game->_assets.fonts.mono36,x+20,y+20);
    window->drawString("   Used by small gun.", _game->_assets.fonts.mono28,x+20,y+70);
}
