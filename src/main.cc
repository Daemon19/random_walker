#include "cookie.h"
#include <SDL2/SDL.h>
#include <iostream>

static const int kWindowW = 960;
static const int kWindowH = 540;
static const SDL_Color kBackgroundColor = {20, 20, 30, 255};

static cookie::Window window;
static bool game_running = true;

void RunGame();

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Gagal menginisialisasi SDL : " << SDL_GetError() << std::endl;
        return -1;
    }

    if (!window.Init("Random Walkers", kWindowW, kWindowH))
    {
        return -1;
    }

    RunGame();

    SDL_Quit();
    return 0;
}

void RunGame()
{
    while (game_running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                game_running = false;
            }
        }

        SDL_SetRenderDrawColor(window.renderer(), kBackgroundColor.r,
                               kBackgroundColor.g, kBackgroundColor.b,
                               kBackgroundColor.a);
        SDL_RenderClear(window.renderer());
        SDL_RenderPresent(window.renderer());
    }
}