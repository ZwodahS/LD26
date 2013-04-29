#include "../items.h"
#include "../Game.h"

BombAmmo::BombAmmo(Game* game,int count)
    :Ammo(Type_Resource_Ammo_Bomb,game,count)
{

}

BombAmmo::~BombAmmo()
{
}
void BombAmmo::draw(Window* window, float delta, int x , int y)
{
    window->draw(_game->_assets.inventory.inventoryBG,x,y);
    window->draw(_game->_assets.inventory.bombAmmo,x,y);
}
void BombAmmo::drawInfo(Window* window, float delta, int x, int y)
{
    window->drawString("Bomb Ammo", _game->_assets.fonts.mono36,x+20,y+20);
    window->drawString("   Used by Bomb Launcher.", _game->_assets.fonts.mono28,x+20,y+70);
}
