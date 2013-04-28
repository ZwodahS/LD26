#include "../items.h"
#include "../Game.h"

BombAmmo::BombAmmo(Game* game,int count)
    :Ammo(Type_Resource_Ammo_Bomb,game,count)
{

}

BombAmmo::~BombAmmo()
{
}
void BombAmmo::draw(Window* window, float delta, int x , int y)
{
}
