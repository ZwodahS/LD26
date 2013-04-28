#include "../items.h"
#include "../Game.h"
Wrench::Wrench(Game* game)
    :Equipment(Type_Equipment_Wrench,game)
{
}

Wrench::~Wrench()
{
}
void Wrench::draw(Window* window, float delta, int x , int y)
{
}
