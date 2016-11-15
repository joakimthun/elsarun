#include "input_manager.h"

#include <SDL.h>
#include <array>
#include <vector>

namespace elsa {
    namespace input {

        auto constexpr MAX_NUM_EVENTS = static_cast<std::size_t>(InputEvent::MAX_VALUE);
        static std::array<std::vector<std::function<void(float)>>, MAX_NUM_EVENTS> callbacks;

        void InputManager::handle_input(float dt)
        {
            SDL_Event e;
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                {
                    raise_event(InputEvent::Quit, dt);
                }

                if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
                {
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_LEFT:
                        raise_event(InputEvent::Left_Down, dt);
                        break;
                    case SDLK_RIGHT:
                        raise_event(InputEvent::Right_Down, dt);
                        break;
                    }
                }
                else if (e.type == SDL_KEYUP && e.key.repeat == 0)
                {
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_LEFT:
                        raise_event(InputEvent::Left_Up, dt);
                        break;
                    case SDLK_RIGHT:
                        raise_event(InputEvent::Right_Up, dt);
                        break;
                    }
                }

            }
        }

        void InputManager::register_callback(InputEvent e, std::function<void(float)> callback)
        {
            callbacks[static_cast<std::size_t>(e)].push_back(callback);
        }

        void InputManager::raise_event(InputEvent e, float dt)
        {
            for (auto& callback : callbacks[static_cast<std::size_t>(e)])
            {
                callback(dt);
            }
        }
    }
}