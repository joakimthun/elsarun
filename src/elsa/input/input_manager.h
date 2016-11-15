#pragma once

#include <functional>

#include "../typedef.h"

namespace elsa {
    namespace input {

        enum class InputEvent : u16
        {
            Quit,
            Left,
            Right
        };

        //auto constexpr MAX_NUM_EVENTS = static_cast<std::size_t>(std::numeric_limits<InputEvent>::max());

        class InputManager
        {
        public:
            static void handle_input();
            static void register_callback(InputEvent e, std::function<void()> callback);

        private:
            InputManager() = delete;
            static void raise_event(InputEvent e);
        };
    }
}