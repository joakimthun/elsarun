#include "texture.h"

#include <SDL_image.h>

#include "renderer2d.h"
#include "../errors/elsa_exception.h"

namespace elsa {
    namespace rendering {

        Texture::Texture() : texture_(nullptr) {}

        Texture::~Texture()
        {
            SDL_DestroyTexture(texture_);
        }

        std::unique_ptr<Texture> Texture::load_from_file(const std::string& path, const Renderer2D* renderer)
        {
            auto texture = std::make_unique<Texture>();
            auto surface = IMG_Load(path.c_str());

            if (surface == nullptr)
            {
                throw errors::ElsaException(IMG_GetError());
            }

            texture->texture_ = SDL_CreateTextureFromSurface(renderer->renderer_, surface);
            SDL_FreeSurface(surface);

            if (texture->texture_ == nullptr)
            {
                throw errors::ElsaException(SDL_GetError());
            }

            if (SDL_QueryTexture(texture->texture_, nullptr, nullptr, &texture->width, &texture->height) != 0)
            {
                throw errors::ElsaException(SDL_GetError());
            }

            return texture;
        }

    }
}
