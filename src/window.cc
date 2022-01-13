#include "window.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <stdexcept>
#include <string.h>

namespace cookie
{
    Window::Window(const std::string &title, int w, int h)
    {
        if (!Init(title, w, h))
        {
            throw std::runtime_error("Gagal membuat objek Window");
        }
    }

    Window::~Window()
    {
        if (window_ != nullptr)
        {
            SDL_DestroyWindow(window_);
        }
        if (renderer_ != nullptr)
        {
            SDL_DestroyRenderer(renderer_);
        }
    }

    bool Window::Init(const std::string &title, int w, int h)
    {
        window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED, w, h, 0);
        if (window_ == nullptr)
        {
            std::cerr << "Gagal membuat window : " << SDL_GetError() << std::endl;
            return false;
        }

        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
        if (renderer_ == nullptr)
        {
            std::cerr << "Gagal membuat renderer : " << SDL_GetError() << std::endl;
            return false;
        }

        return true;
    }

    SDL_Renderer *Window::renderer()
    {
        return renderer_;
    }
}