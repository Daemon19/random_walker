#include <random>

namespace cookie
{
    int Randint(int end)
    {
        return rand() % (end + 1);
    }

    int Randint(int start, int end)
    {
        return Randint(end - start) + end;
    }
}