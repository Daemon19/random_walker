#pragma once

namespace cookie
{
    struct Vector2
    {
        float x, y;

        Vector2(float x, float y);
        Vector2();

        Vector2 operator+(const Vector2 &other);
        void operator+=(const Vector2 &other);
    };
}