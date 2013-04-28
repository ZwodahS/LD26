#include "../screen.h"
#include "../Game.h"
#include "../objects.h"
StatsScreen::StatsScreen(Game* game, PlayerBot* player)
    :Screen(game)
{
    this->player = player;
}
StatsScreen::~StatsScreen()
{
    delete assignedWindow;
}
void StatsScreen::init(Display *display, Window* parent)
{
    assignedWindow = parent->createWindow(80,80,480,480);
}

bool StatsScreen::update(InputManager* inputs, float delta)
{

}

void StatsScreen::draw(float delta)
{
    assignedWindow->draw(game->_assets.others.statsBackground,0,0);
    std::string info = "HP:";
    info+= toString(player->getCurrentHp());
    info+= "/";
    info+= toString(player->getMaxHp());
    assignedWindow->drawString(info,game->_assets.fonts.mono36,Color(0,0,0),25,25);

    info= "Action:";
    info+= toString(player->getActionPoints());
    info+= "/";
    info+= toString(player->getMaxPoints());
    assignedWindow->drawString(info,game->_assets.fonts.mono36,Color(0,0,0),25,70);
    
    info= "Move Cost:";
    info+= toString(player->getMoveCost());
    assignedWindow->drawString(info,game->_assets.fonts.mono36,Color(0,0,0),25,115);
}
