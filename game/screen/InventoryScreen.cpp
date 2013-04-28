#include "../screen.h"

InventoryScreen::InventoryScreen(Game* game,Inventory* inventory)
    :Screen(game)
{
    this->inventory = inventory;
    selectedIndex = 0;
}

void InventoryScreen::init(Display* display, Window* parent)
{
    assignedWindow = parent->createWindow(35,35,570,570);
}

bool InventoryScreen::update(InputManager* inputs, float delta)
{
            
}

void InventoryScreen::draw(float delta)
{
    inventory->draw(assignedWindow,delta,selectedIndex);
}
