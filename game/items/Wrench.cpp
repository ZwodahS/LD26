#include "../items.h"
#include "../Game.h"
Wrench::Wrench(Game* game)
    :Equipment(Type_Equipment_Wrench,game)
{
}

Wrench::~Wrench()
{
}
void Wrench::draw(Window* window, float delta, int x , int y)
{
    window->draw(_game->_assets.inventory.inventoryBG,x,y);
    window->draw(_game->_assets.inventory.wrench,x,y);
}
void Wrench::drawInfo(Window* window, float delta, int x, int y)
{
    window->drawString("Wrench", _game->_assets.fonts.mono36,x+20,y+20);
    window->drawString("   Can be used to repair yourself.", _game->_assets.fonts.mono28,x+20,y+70);
    window->drawString("   Uses Scrap metal.", _game->_assets.fonts.mono28,x+20,y+95);
}

int Wrench::getActionCost()
{
    return 0;
}
