#include "../items.h"
#include "../Game.h"
ScrapMetal::ScrapMetal(Game* game,int count)
    :Resource(Type_Resource_ScrapMetal,game,count)
{
}

ScrapMetal::~ScrapMetal()
{
}
void ScrapMetal::draw(Window* window, float delta, int x , int y)
{
}
