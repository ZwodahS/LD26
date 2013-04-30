#include "../items.h"
#include "../Game.h"
BombLauncher::BombLauncher(Game* game)
    :Weapon(Type_Equipment_BombLauncher,game)
{

}
BombLauncher::~BombLauncher()
{
}
void BombLauncher::draw(Window* window, float delta, int x , int y)
{
    window->draw(_game->_assets.inventory.inventoryBG,x,y);
    window->draw(_game->_assets.inventory.bombLauncher,x,y);
}
void BombLauncher::drawInfo(Window* window, float delta, int x, int y)
{
    window->drawString("Bomb Launcher", _game->_assets.fonts.mono36,x+20,y+20);
    window->drawString("   Uses Bomb Ammo. Deals damage to", _game->_assets.fonts.mono28,x+20,y+70);
    window->drawString("   enemy or destroy wall.", _game->_assets.fonts.mono28,x+20,y+95);
}

bool BombLauncher::canFireAt(World* world, PlayerBot* player, Grid targetLocation)
{
    return true;
}
void BombLauncher::fireAt(World* world, PlayerBot* player, Grid targetLocation)
{

}

int BombLauncher::getActionCost()
{
    return 2;
}
