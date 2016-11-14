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

        class Renderer
        {
            friend class Texture;
        public:
            Renderer();
            ~Renderer();
            
            static std::unique_ptr<Renderer> create(const Window* window);
            void set_draw_color(Color color);
            void clear();
            void present();
            void render_texture(const Texture* texture);
            void fill_rect(i32 x, i32 y, i32 width, i32 height);

        private:
            SDL_Renderer* renderer_;
        };
    }
}
