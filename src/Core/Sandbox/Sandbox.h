#pragma once

#include "SDL2/SDL.h"

class Sandbox
{
public:
    virtual void start(){}
    virtual void onUpdate(double deltaTime){}
    virtual void onEvent(const SDL_Event& event){}
    virtual void onGUI(){}
    virtual ~Sandbox() = default;
};
