#include "../items.h"
#include "../Game.h"
HeavyAmmo::HeavyAmmo(Game* game, int count)
    :Ammo(Type_Resource_Ammo_Heavy,game,count)
{

}

HeavyAmmo::~HeavyAmmo()
{
}
void HeavyAmmo::draw(Window* window, float delta, int x, int y)
{
    window->draw(_game->_assets.inventory.inventoryBG,x,y);
    window->draw(_game->_assets.inventory.heavyAmmo,x,y);
}

void HeavyAmmo::drawInfo(Window* window, float delta, int x , int y)
{
    window->drawString("Heavy Ammo", _game->_assets.fonts.mono36,x+20,y+20);
    window->drawString("   Used by bigger gun.", _game->_assets.fonts.mono28,x+20,y+70);
}
