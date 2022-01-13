#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace cookie
{
    class Window
    {
    private:
        SDL_Window *window_ = nullptr;
        SDL_Renderer *renderer_ = nullptr;

    public:
        Window() = default;

        Window(const std::string &title, int w, int h);
        ~Window();

        bool Init(const std::string &title, int w, int h);

        SDL_Renderer *renderer();
    };
}