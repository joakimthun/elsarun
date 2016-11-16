#pragma once

#include <SDL.h>
#include <memory>

#include "../typedef.h"
#include "color.h"

namespace elsa {
    namespace rendering {

        class Window;
        class Texture;
        struct Color;

        class Renderer2D
        {
            friend class Texture;
        public:
            Renderer2D();
            ~Renderer2D();
            
            static std::unique_ptr<Renderer2D> create(const Window* window, bool vsync);
            void set_draw_color(Color color);
            void clear();
            void present();
            void render_texture(const Texture* texture, i32 x, i32 y);
            void fill_rect(i32 x, i32 y, i32 width, i32 height);
            void render_line(i32 x1, i32 y1, i32 x2, i32 y2);

        private:
            SDL_Renderer* renderer_;
        };
    }
}
