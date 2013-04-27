#ifndef _GAME_INPUTS_H_
#define _GAME_INPUTS_H_

#include "../framework/zf_framework.h"
class InputManager
{
    public:
        KeyboardState up;
        KeyboardState down;
        KeyboardState left;
        KeyboardState right;

        InputManager();



        void processInputs(float delta);

};
#endif
