#include "texture.h"

#include "renderer.h"
#include "../errors/elsa_exception.h"

namespace elsa {
    namespace rendering {

        Texture::Texture() : texture_(nullptr) {}

        Texture::~Texture()
        {
            SDL_DestroyTexture(texture_);
        }

        std::unique_ptr<Texture> Texture::load_from_bmp(const char* path, const Renderer* renderer)
        {
            auto texture = std::make_unique<Texture>();
            auto surface = SDL_LoadBMP(path);

            if (surface == nullptr)
            {
                throw errors::ElsaException(SDL_GetError());
            }

            texture->texture_ = SDL_CreateTextureFromSurface(renderer->renderer_, surface);
            SDL_FreeSurface(surface);

            if (texture->texture_ == nullptr)
            {
                throw errors::ElsaException(SDL_GetError());
            }

            return texture;
        }

    }
}
