#pragma once

#include <SDL.h>
#include <memory>

#include "../typedef.h"

namespace elsa {
    namespace rendering {

        class Renderer2D;

        class Texture
        {
            friend class Renderer2D;
        public:
            Texture();
            ~Texture();

            static std::unique_ptr<Texture> load_from_bmp(const char* path, const Renderer2D* renderer);

            i32 width = 0;
            i32 height = 0;
        private:
            SDL_Texture* texture_;
        };
    }
}