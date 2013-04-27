#ifndef _GAME_GAME_H_
#define _GAME_GAME_H_
#include "InputManager.h"
#include "Assets.h"
#include "../framework/zf_framework.h"
class Game
{
    public:
        Game(Display* display, SoundControl* sc);
        ~Game();

        void run();

        Display* _display;
        SoundControl* _sound;
        InputManager* _inputs;

        Assets _assets;
    protected:
            
    private:
        void initAssets();        
};
#endif

