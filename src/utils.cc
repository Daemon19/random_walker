#include <random>
#include <SDL2/SDL.h>

namespace cookie
{
    int Randint()
    {
        return rand();
    }

    int Randint(int end)
    {
        return rand() % (end + 1);
    }

    int Randint(int start, int end)
    {
        return Randint(end - start) + start;
    }
}