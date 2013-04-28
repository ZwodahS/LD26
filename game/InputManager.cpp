#include "InputManager.h"

#include "SDL/SDL.h"

InputManager::InputManager()
{
    up = KeyboardState(SDLK_w);
    down = KeyboardState(SDLK_s);
    left = KeyboardState(SDLK_a);
    right = KeyboardState(SDLK_d);
    menu = KeyboardState(SDLK_ESCAPE);
    fire = KeyboardState(SDLK_f);
    inventory = KeyboardState(SDLK_i);
    selecttarget = KeyboardState(SDLK_SPACE);
}


void InputManager::processInputs(float delta)
{
    zf_inputs::processKey(&up);
    zf_inputs::processKey(&down);
    zf_inputs::processKey(&left);
    zf_inputs::processKey(&right);
    zf_inputs::processKey(&menu);
    zf_inputs::processKey(&fire);
    zf_inputs::processKey(&inventory);
    zf_inputs::processKey(&selecttarget);
}
