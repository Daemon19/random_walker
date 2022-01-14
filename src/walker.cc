#include "../include/walker.h"
#include "../include/cookie/cookie.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

Walker::Walker(cookie::Vector2 pos)
    : Circle(pos.x, pos.y, kRadius)
{
}

void Walker::Update(float dt)
{
    last_pos_ = pos();
    x += cookie::Randint(-kMaxVel, kMaxVel) * dt;
    y += cookie::Randint(-kMaxVel, kMaxVel) * dt;
}

void Walker::DrawMovement(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, kMovementColor.r, kMovementColor.g,
                           kMovementColor.b, kMovementColor.a);
    SDL_RenderDrawLine(renderer, last_pos_.x, last_pos_.y, x, y);
}

void Walker::DrawPos(SDL_Renderer *renderer)
{
    DrawFilledCircle(renderer, kPosColor);
}

const float Walker::kMaxVel = 4;
const SDL_Color Walker::kPosColor = {255, 50, 50, 255};
const SDL_Color Walker::kMovementColor = {255, 255, 255, 255};
const int Walker::kRadius = 3;