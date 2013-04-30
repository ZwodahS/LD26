#include "../items.h"
#include "../Game.h"
Augmentation::Augmentation(Game* game,int ap, int hp, int vision)
    :Passive(Type_Passive_Augmentation,game)
{
    this->bonusAp = ap;
    this->bonusHp = hp;
    this->bonusVision = vision;
}
Augmentation::~Augmentation()
{
}

void Augmentation::draw(Window* window, float delta,int x , int y)
{
    window->draw(_game->_assets.inventory.inventoryBG,x,y);
    window->draw(_game->_assets.inventory.augmentation,x,y);
}

void Augmentation::drawInfo(Window* window, float delta, int x, int y)
{
    window->drawString("Augmentation",_game->_assets.fonts.mono36,x+20,y+20);
    int yoff = 70;
    if(bonusHp != 0)
    {
        std::string s = "   Health + " + toString(bonusHp);
        window->drawString(s,_game->_assets.fonts.mono28,x+20,y+yoff);
        yoff+=30;
    }
    if(bonusAp != 0)
    {
        std::string s = "   Action Point + " + toString(bonusAp);
        window->drawString(s,_game->_assets.fonts.mono28,x+20,y+yoff);
        yoff+=30;
    }
    if(bonusVision != 0)
    {
        std::string s = "   Bonus Vision + " + toString(bonusVision);
        window->drawString(s,_game->_assets.fonts.mono28,x+20,y+yoff);
        yoff+=30;
    }
}


