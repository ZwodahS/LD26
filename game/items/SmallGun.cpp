#include "../items.h"
#include "../Game.h"
SmallGun::SmallGun(Game* game)
    :Equipment(Type_Equipment_SmallArm,game)
{

}

SmallGun::~SmallGun()
{
}
void SmallGun::draw(Window* window, float delta, int x , int y)
{
}
