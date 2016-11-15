#pragma once

#include <functional>

#include "../typedef.h"

namespace elsa {
    namespace input {

        enum class InputEvent : u16
        {
            Quit,
            Left_Up,
            Left_Down,
            Right_Up,
            Right_Down,
            Up_Up,
            Up_Down,
            Down_Up,
            Down_Down,
            MAX_VALUE
        };

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