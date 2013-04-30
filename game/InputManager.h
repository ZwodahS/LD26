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
        KeyboardState menu; // ESC
        KeyboardState fire; // fire weapon
        KeyboardState inventory; // Open inventory
        KeyboardState select; // enter / space
        KeyboardState stats;
        KeyboardState equip;
        InputManager();



        void processInputs(float delta);

};
#endif
