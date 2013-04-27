#include "../screen.h"
#include "../Game.h"
#include "../../framework/zf_framework.h"


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

bool MainScreen::update(InputManager* controller, float delta)
{
    return true;
}

void MainScreen::draw(float delta)
{
}
