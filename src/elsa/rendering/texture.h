#pragma once

#include <SDL.h>
#include <memory>

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

        private:
            SDL_Texture* texture_;
        };
    }
}