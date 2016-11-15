#pragma once

#include <SDL.h>
#include <string>
#include <memory>

#include "../typedef.h"

namespace elsa {
    namespace rendering {

        class Renderer2D;

        class Window
        {
            friend class Renderer2D;
        public:
            Window();
            ~Window();

            static std::unique_ptr<Window> create(const std::string& title, i32 width, i32 height);

            i32 width;
            i32 height;
        private:
            SDL_Window* window_;
        };
    }
}