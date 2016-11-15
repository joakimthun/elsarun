#include "input_manager.h"

#include <SDL.h>
#include <array>
#include <vector>

namespace elsa {
    namespace input {

        static std::array<std::vector<std::function<void()>>, InputManager::max_num_events()> callbacks;

        void InputManager::handle_input()
        {
            SDL_Event e;
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                {
                    raise_event(InputEvent::Quit);
                }

                if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
                {
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_LEFT:
                        raise_event(InputEvent::Left_Down);
                        break;
                    case SDLK_RIGHT:
                        raise_event(InputEvent::Right_Down);
                        break;
                    case SDLK_UP:
                        raise_event(InputEvent::Up_Down);
                        break;
                    case SDLK_DOWN:
                        raise_event(InputEvent::Down_Down);
                        break;
                    }
                }
                else if (e.type == SDL_KEYUP && e.key.repeat == 0)
                {
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_LEFT:
                        raise_event(InputEvent::Left_Up);
                        break;
                    case SDLK_RIGHT:
                        raise_event(InputEvent::Right_Up);
                        break;
                    case SDLK_UP:
                        raise_event(InputEvent::Up_Up);
                        break;
                    case SDLK_DOWN:
                        raise_event(InputEvent::Down_Up);
                        break;
                    }
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