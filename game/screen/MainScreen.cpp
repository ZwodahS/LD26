#include "../screen.h"
#include "../Game.h"
#include "../../framework/zf_framework.h"

#include <iostream>
MainScreen::MainScreen(Game* game)
    :Screen(game)
{
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
    return true;
}

void MainScreen::draw(float delta)
{
    assignedWindow->drawString("Minimialism Bot", game->_assets.fonts.mono,20,20);
}
