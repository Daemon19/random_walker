#include "cookie/cookie.h"
#include "walker.h"
#include <SDL2/SDL.h>
#include <array>
#include <iostream>
#include <memory>

static const int kWindowW = 960;
static const int kWindowH = 540;
static const int kWindowHalfW = kWindowW / 2;
static const int kWindowHalfH = kWindowH / 2;

static const int kTargetFps = 60;
static const int kFrameTime = 1000 / 60;

static const SDL_Color kBackgroundColor = {20, 20, 30, 255};
static const int kWalkerCount = 10;

static cookie::Window window("Random Walkers", kWindowW, kWindowH);

static cookie::Texture walker_movement_texture(SDL_CreateTexture(
    window.renderer(), SDL_PIXELFORMAT_RGB888,
    SDL_TEXTUREACCESS_TARGET, kWindowW, kWindowH));

static std::shared_ptr<std::array<Walker, kWalkerCount>> walkers;

static bool game_paused = false;
static bool game_running = true;

void Setup();
void MainLoop();

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Gagal menginisialisasi SDL : " << SDL_GetError() << std::endl;
        return -1;
    }

    Setup();
    MainLoop();

    SDL_Quit();
    return 0;
}

void Setup()
{
    SDL_SetRenderDrawColor(window.renderer(), kBackgroundColor.r,
                           kBackgroundColor.g, kBackgroundColor.b,
                           kBackgroundColor.a);
    SDL_SetRenderTarget(window.renderer(), walker_movement_texture);
    SDL_RenderClear(window.renderer());
    SDL_SetRenderTarget(window.renderer(), nullptr);

    walkers = std::make_shared<std::array<Walker, kWalkerCount>>();

    for (Walker &w : *walkers)
    {
        w = Walker(cookie::Vector2(kWindowHalfW, kWindowHalfH));
    }
}

void MainLoop()
{
    static Uint32 last_ticks = SDL_GetTicks();

    while (game_running)
    {
        Uint32 current_ticks = SDL_GetTicks();
        Uint32 delta_ticks = (current_ticks - last_ticks);
        last_ticks = current_ticks;
        float dt = delta_ticks / (float)kFrameTime;

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                game_running = false;
            }
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_r)
                {
                    Setup();
                }
            }
            if (e.type == SDL_KEYUP)
            {
                if (e.key.keysym.sym == SDLK_SPACE)
                {
                    game_paused = !game_paused;
                }
            }
        }

        if (game_paused)
        {
            dt = 0;
        }

        SDL_SetRenderDrawColor(window.renderer(), kBackgroundColor.r,
                               kBackgroundColor.g, kBackgroundColor.b,
                               kBackgroundColor.a);
        SDL_RenderClear(window.renderer());
        SDL_RenderCopy(window.renderer(), walker_movement_texture,
                       nullptr, nullptr);

        for (Walker &w : *walkers)
        {
            w.Update(dt);
            w.DrawPos(window.renderer());
            SDL_SetRenderTarget(window.renderer(), walker_movement_texture);
            w.DrawMovement(window.renderer());
            SDL_SetRenderTarget(window.renderer(), nullptr);
        }

        SDL_RenderPresent(window.renderer());

        if (delta_ticks < kFrameTime)
        {
            SDL_Delay(kFrameTime - delta_ticks);
        }
    }
}