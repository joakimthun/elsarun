#include "renderer2d.h"

#include "window.h"
#include "texture.h"
#include "../errors/elsa_exception.h"

namespace elsa {
    namespace rendering {

        Renderer2D::Renderer2D() : renderer_(nullptr) {}

        Renderer2D::~Renderer2D()
        {
            SDL_DestroyRenderer(renderer_);
        }

        std::unique_ptr<Renderer2D> Renderer2D::create(const Window* window, bool vsync)
        {
            auto renderer = std::make_unique<Renderer2D>();

            u32 flags = SDL_RENDERER_ACCELERATED;

            if (vsync)
            {
                flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
            }

            renderer->renderer_ = SDL_CreateRenderer(window->window_, -1, flags);
            if (renderer->renderer_ == nullptr)
            {
                throw errors::ElsaException(SDL_GetError());
            }

            return renderer;
        }

        void Renderer2D::set_draw_color(Color color)
        {
            SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
        }

        void Renderer2D::clear()
        {
            SDL_RenderClear(renderer_);
        }

        void Renderer2D::present()
        {
            SDL_RenderPresent(renderer_);
        }

        void Renderer2D::render_texture(const Texture* texture, i32 x, i32 y)
        {
            SDL_Rect rectangle;

            rectangle.x = x - texture->width / 2;
            rectangle.y = y - texture->height / 2;
            rectangle.w = texture->width;
            rectangle.h = texture->height;

            SDL_RenderCopy(renderer_, texture->texture_, nullptr, &rectangle);
        }

        void Renderer2D::fill_rect(i32 x, i32 y, i32 width, i32 height)
        {
            SDL_Rect rectangle;

            rectangle.x = x - width / 2;
            rectangle.y = y - height / 2;
            rectangle.w = width;
            rectangle.h = height;

            SDL_RenderFillRect(renderer_, &rectangle);
        }
    }
}
