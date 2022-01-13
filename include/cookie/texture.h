#pragma once

#include <SDL2/SDL.h>

namespace cookie
{
    class Texture
    {
    private:
        SDL_Texture *texture_ = nullptr;

    public:
        Texture() = default;
        Texture(const Texture &) = delete;
        Texture(SDL_Texture *texture);
        ~Texture();

        bool Init(SDL_Texture *texture);

        operator SDL_Texture *();

    private:
        void Free();
    };
}