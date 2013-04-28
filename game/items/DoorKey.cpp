#include "../items.h"
#include "../Game.h"

DoorKey::DoorKey(Game* game,int color)
    :Passive(Type_Passive_DoorKey,game)
{
    this->color = color;
}
DoorKey::~DoorKey()
{
}
void DoorKey::draw(Window* window, float delta, int x , int y)
{
}
