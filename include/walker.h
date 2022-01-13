#pragma once

#include "cookie/cookie.h"
#include <SDL2/SDL.h>

class Walker
{
private:
    static const float kMaxVel;
    static const SDL_Color kLineColor;
    static const SDL_Color kPointColor;
    static const int kDrawRadius;
    cookie::Vector2 last_pos_;
    cookie::Vector2 pos_;

public:
    Walker() = default;
    Walker(cookie::Vector2 pos);
    void Update(float dt);
    void DrawMovement(SDL_Renderer *renderer);
    void DrawPos(SDL_Renderer *renderer);
};
