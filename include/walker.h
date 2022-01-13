#pragma once

#include "cookie/cookie.h"
#include <SDL2/SDL.h>

class Walker
{
private:
    static const float kMaxVel;
    static const SDL_Color kColor;
    cookie::Vector2 pos_;

public:
    Walker(cookie::Vector2 pos);
    void Update();
    void Draw(SDL_Renderer *renderer);
};