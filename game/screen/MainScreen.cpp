#include "../screen.h"
#include "../Game.h"
#include "../../framework/zf_framework.h"

#include <iostream>
MainScreen::MainScreen(Game* game)
    :Screen(game)
{
    color = 255;
}

MainScreen::~MainScreen()
{
    delete assignedWindow;
}

void MainScreen::init(Display* display, Window* parent)
{
    assignedWindow = parent->createWindow(); 
}

bool MainScreen::update(InputManager* inputs, float delta)
{
    //TODO : set it to a slower timing :D
    color -= delta * 600;
    if(color < 0)
    {
        game->toGameScreen();
        return false;
    }
    return true;
}

void MainScreen::draw(float delta)
{
    assignedWindow->drawString("Minimialism", game->_assets.fonts.mono36,Color(color,color,color),50,220);
    assignedWindow->drawString("   - The philosophy of having just what you need.", game->_assets.fonts.mono20,Color(color,color,color),20,260);
}
