#pragma once

#include "cookie/cookie.h"
#include <SDL2/SDL.h>

class Walker : cookie::Circle
{
private:
    static const float kMaxVel;
    static const SDL_Color kMovementColor;
    static const SDL_Color kPosColor;
    static const int kRadius;
    cookie::Vector2 last_pos_;

public:
    Walker() = default;
    Walker(cookie::Vector2 pos);
    void Update(float dt);
    void DrawMovement(SDL_Renderer *renderer);
    void DrawPos(SDL_Renderer *renderer);
};
