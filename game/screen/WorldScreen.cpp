#include "../screen.h"
#include "../Game.h"

#include "../../framework/zf_framework.h"

WorldScreen::WorldScreen(Game* game,World* world)
    :Screen(game)
{
    this->world = world;
}

WorldScreen::~WorldScreen()
{
}

void WorldScreen::init(Display* display, Window* parent)
{
    assignedWindow = parent->createCameraWindow(world->getDimension(),Rectangle(288,288,64,64));
}

bool WorldScreen::update(InputManager* inputs, float delta)
{
    return true;
}

void WorldScreen::draw(float delta)
{
    world->draw(assignedWindow,delta);
    assignedWindow->finalize();
}

