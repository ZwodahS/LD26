#include "../items.h"
#include "../Game.h"
SniperRifle::SniperRifle(Game* game)
    :Weapon(Type_Equipment_SniperRifle,game)
{
    
}
SniperRifle::~SniperRifle()
{
}

void SniperRifle::draw(Window* window, float delta, int x , int y)
{
    window->draw(_game->_assets.inventory.inventoryBG,x,y);
    window->draw(_game->_assets.inventory.sniperRifle,x,y);
}

void SniperRifle::drawInfo(Window* window, float delta, int x , int y)
{
    window->drawString("Sniper Rifle",_game->_assets.fonts.mono36,x+20,y+20);
    window->drawString("   High range weapon. Uses heavy ammo.",_game->_assets.fonts.mono28,x+20,y+70);
}
