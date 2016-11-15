#include "input_component.h"

#include "../input/input_manager.h"

#include <iostream>

namespace elsa {
    namespace components {

        void InputComponent::init()
        {
            input::InputManager::register_callback(input::InputEvent::Left_Up, std::bind(&InputComponent::handle_left_up_event, this, std::placeholders::_1));
            input::InputManager::register_callback(input::InputEvent::Left_Down, std::bind(&InputComponent::handle_left_down_event, this, std::placeholders::_1));
            input::InputManager::register_callback(input::InputEvent::Right_Up, std::bind(&InputComponent::handle_right_up_event, this, std::placeholders::_1));
            input::InputManager::register_callback(input::InputEvent::Right_Down, std::bind(&InputComponent::handle_right_down_event, this, std::placeholders::_1));
        }

        void InputComponent::handle_left_up_event(float dt)
        {
            std::cout << "handle_left_up_event" << dt << std::endl;
        }

        void InputComponent::handle_left_down_event(float dt)
        {
            std::cout << "handle_left_down_event" << dt << std::endl;
        }

        void InputComponent::handle_right_up_event(float dt)
        {
            std::cout << "handle_right_up_event" << dt << std::endl;
        }

        void InputComponent::handle_right_down_event(float dt)
        {
            std::cout << "handle_right_down_event" << dt << std::endl;
        }
    }
}
