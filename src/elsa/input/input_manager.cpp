#include "input_manager.h"

#include <SDL.h>
#include <array>
#include <vector>

namespace elsa {
    namespace input {

        static std::array<std::vector<std::function<void()>>, 5> callbacks;

        void InputManager::handle_input()
        {
            SDL_Event e;
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                {
                    raise_event(InputEvent::Quit);
                }

                switch (e.key.keysym.sym)
                {
                case SDLK_LEFT: 
                    raise_event(InputEvent::Left); 
                    break;
                case SDLK_RIGHT: 
                    raise_event(InputEvent::Right); 
                    break;
                }
            }
        }

        void InputManager::register_callback(InputEvent e, std::function<void()> callback)
        {
            callbacks[static_cast<std::size_t>(e)].push_back(callback);
        }

        void InputManager::raise_event(InputEvent e)
        {
            for (auto& callback : callbacks[static_cast<std::size_t>(e)])
            {
                callback();
            }
        }
    }
}