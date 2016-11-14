#include "renderer.h"

#include "window.h"
#include "texture.h"
#include "../errors/elsa_exception.h"

namespace elsa {
    namespace rendering {

        Renderer::Renderer() : renderer_(nullptr) {}

        Renderer::~Renderer()
        {
            SDL_DestroyRenderer(renderer_);
        }

        std::unique_ptr<Renderer> Renderer::create(const Window* window)
        {
            auto renderer = std::make_unique<Renderer>();

            renderer->renderer_ = SDL_CreateRenderer(window->window_, -1, SDL_RENDERER_ACCELERATED);
            if (renderer->renderer_ == nullptr)
            {
                throw errors::ElsaException(SDL_GetError());
            }

            return renderer;
        }

        void Renderer::set_draw_color(Color color)
        {
            SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
        }

        void Renderer::clear()
        {
            SDL_RenderClear(renderer_);
        }

        void Renderer::present()
        {
            SDL_RenderPresent(renderer_);
        }

        void Renderer::render_texture(const Texture* texture)
        {
            SDL_RenderCopy(renderer_, texture->texture_, nullptr, nullptr);
        }

        void Renderer::fill_rect(i32 x, i32 y, i32 width, i32 height)
        {
            SDL_Rect rectangle;

            rectangle.x = x;
            rectangle.y = y;
            rectangle.w = width;
            rectangle.h = height;

            SDL_RenderFillRect(renderer_, &rectangle);
        }
    }
}
