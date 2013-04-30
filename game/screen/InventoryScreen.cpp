#include "../screen.h"
#include "../objects.h"
InventoryScreen::InventoryScreen(Game* game,PlayerBot* player)
    :Screen(game)
{
    this->inventory = player->inventory;
    this->player = player;
    selectedIndex = 0;
}

void InventoryScreen::init(Display* display, Window* parent)
{
    assignedWindow = parent->createWindow(35,35,570,570);
}

bool InventoryScreen::update(InputManager* inputs, float delta)
{
    int newIndex = selectedIndex;
    if(inputs->up.thisPressed)
    {
        newIndex = newIndex - 10;
    }
    else if(inputs->down.thisPressed)
    {
        newIndex = newIndex + 10;
    }
    else if(inputs->left.thisPressed)
    {
        if(newIndex % 10 != 0)
        {
            newIndex -= 1;
        }
    }
    else if(inputs->right.thisPressed)
    {
        if(newIndex % 10 != 9)
        {
            newIndex += 1;
        }
    }
    else if(inputs->equip.thisPressed)
    {
        if(inventory->_items[selectedIndex]->equippable())
        {
            player->equipWeapon( (Weapon*)inventory->_items[selectedIndex]);
        }
    }
    if(newIndex != selectedIndex)
    {
        if(newIndex < inventory->_items.size() && newIndex >= 0)
        {
            selectedIndex = newIndex;
        }
    }
}

void InventoryScreen::draw(float delta)
{
    inventory->draw(assignedWindow,delta,selectedIndex);
}
