#include "../include/walker.h"
#include "../include/cookie/cookie.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

Walker::Walker(cookie::Vector2 pos)
    : pos_(pos)
{
}

void Walker::Update(float dt)
{
    last_pos_ = pos_;
    pos_.x += cookie::Randint(-kMaxVel, kMaxVel) * dt;
    pos_.y += cookie::Randint(-kMaxVel, kMaxVel) * dt;
}

void Walker::DrawMovement(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, kLineColor.r, kLineColor.g,
                           kLineColor.b, kLineColor.a);
    SDL_RenderDrawLine(renderer, last_pos_.x, last_pos_.y, pos_.x, pos_.y);
}

void Walker::DrawPos(SDL_Renderer *renderer)
{
    filledCircleRGBA(renderer, pos_.x, pos_.y, kDrawRadius, kPointColor.r,
                     kPointColor.g, kPointColor.b, kPointColor.a);
}

const float Walker::kMaxVel = 4;
const SDL_Color Walker::kPointColor = {255, 50, 50, 255};
const SDL_Color Walker::kLineColor = {255, 255, 255, 255};
const int Walker::kDrawRadius = 3;