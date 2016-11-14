#include "window.h"

#include <SDL.h>

#include "../errors/elsa_exception.h"

namespace elsa {
    namespace rendering {

        Window::Window() : window_(nullptr), width(0), height(0)
        {
        }

        Window::~Window()
        {
            SDL_DestroyWindow(window_);
        }

        std::unique_ptr<Window> Window::create(const std::string & title, i32 width, i32 height)
        {
            auto window = std::make_unique<Window>();

            window->window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
            if (window->window_ == nullptr)
            {
                throw errors::ElsaException(SDL_GetError());
            }

            return window;
        }

    }
}
