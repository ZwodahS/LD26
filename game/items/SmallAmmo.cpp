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
