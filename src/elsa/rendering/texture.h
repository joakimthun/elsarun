#pragma once

#include <SDL.h>
#include <memory>

namespace elsa {
    namespace rendering {

        class Renderer;

        class Texture
        {
            friend class Renderer;
        public:
            Texture();
            ~Texture();

            static std::unique_ptr<Texture> load_from_bmp(const char* path, const Renderer* renderer);

        private:
            SDL_Texture* texture_;
        };
    }
}