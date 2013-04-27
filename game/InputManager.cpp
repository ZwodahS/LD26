#include "InputManager.h"

#include "SDL/SDL.h"

InputManager::InputManager()
{
    up = KeyboardState(SDLK_w);
    down = KeyboardState(SDLK_s);
    left = KeyboardState(SDLK_a);
    right = KeyboardState(SDLK_d);
}


void InputManager::processInputs(float delta)
{
    zf_inputs::processKey(&up);
    zf_inputs::processKey(&down);
    zf_inputs::processKey(&left);
    zf_inputs::processKey(&right);
}
