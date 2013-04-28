#include "../items.h"
#include "../Game.h"
BombLauncher::BombLauncher(Game* game)
    :Equipment(Type_Equipment_BombLauncher,game)
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
