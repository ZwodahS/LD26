#include "../items.h"
#include "../Game.h"
ScrapMetal::ScrapMetal(Game* game,int count)
    :Resource(Type_Resource_ScrapMetal,game,count)
{
}

ScrapMetal::~ScrapMetal()
{
}
void ScrapMetal::draw(Window* window, float delta, int x , int y)
{
    window->draw(_game->_assets.inventory.inventoryBG,x,y);
    window->draw(_game->_assets.inventory.scrapmetal,x,y);
}
void ScrapMetal::drawInfo(Window* window, float delta, int x, int y)
{
    window->drawString("Scrap Metal", _game->_assets.fonts.mono36,x+20,y+20);
    window->drawString("   Used by Wrench to repair damage", _game->_assets.fonts.mono28,x+20,y+70);
}
