#include "../include/walker.h"
#include "../include/cookie/cookie.h"
#include <SDL2/SDL.h>

Walker::Walker(cookie::Vector2 pos)
    : pos_(pos)
{
}

void Walker::Update()
{
    pos_.x += cookie::Randint(-kMaxVel, kMaxVel);
    pos_.y += cookie::Randint(-kMaxVel, kMaxVel);
}

void Walker::Draw(SDL_Renderer *renderer)
{
    SDL_RenderDrawPoint(renderer, pos_.x, pos_.y);
}

const float Walker::kMaxVel = 5;
const SDL_Color Walker::kColor = {255, 255, 255, 255};