#pragma once

#include <SDL2/SDL.h>
#include "vector2.h"

namespace cookie
{
    struct Circle
    {
        float x, y;
        int radius;

        Circle();
        Circle(float x, float y, int radius);

        void DrawFilledCircle(SDL_Renderer *renderer, const SDL_Color &color);

        Vector2 pos();
        void set_pos(const Vector2 &pos);
    };
}