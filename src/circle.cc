#include "circle.h"
#include "vector2.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

namespace cookie
{
    Circle::Circle()
        : x(0), y(0), radius(0)
    {
    }

    Circle::Circle(float x, float y, int radius)
        : x(x), y(y), radius(radius)
    {
    }

    void Circle::DrawFilledCircle(SDL_Renderer *renderer,
                                  const SDL_Color &color)
    {
        filledCircleRGBA(renderer, (int)x, (int)y, radius,
                         color.r, color.g, color.b, color.a);
    }

    Vector2 Circle::pos()
    {
        return Vector2(x, y);
    }

    void Circle::set_pos(const Vector2 &pos)
    {
        x = pos.x;
        y = pos.y;
    }
}