#include "vector2.h"

namespace cookie
{
    Vector2::Vector2(float x, float y)
        : x(x), y(y)
    {
    }

    Vector2 Vector2::operator+(const Vector2 &other)
    {
        return Vector2(x + other.x, y + other.y);
    }

    void Vector2::operator+=(const Vector2 &other)
    {
        *this = *this + other;
    }
}