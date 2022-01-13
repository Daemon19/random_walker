#include "texture.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <stdexcept>

namespace cookie
{
    Texture::Texture(SDL_Texture *texture)
    {
        if (!Init(texture))
        {
            throw std::runtime_error("Gagal membuat objek Texture");
        }
    }

    Texture::~Texture()
    {
        Free();
    }

    bool Texture::Init(SDL_Texture *texture)
    {
        if (texture == nullptr)
        {
            std::cerr << "[ERROR] Gagal membuat texture : parameter texture tidak boleh NULL" << std::endl;
            return false;
        }
        // Free texture sebelumnya (jika ada)
        Free();

        texture_ = texture;
        return true;
    }

    Texture::operator SDL_Texture *()
    {
        return texture_;
    }

    void Texture::Free()
    {
        if (texture_ != nullptr)
        {
            SDL_DestroyTexture(texture_);
            texture_ = nullptr;
        }
    }
}