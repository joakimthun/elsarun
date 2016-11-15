#include "input_component.h"

#include "../entities/entity.h"
#include "../input/input_manager.h"
#include "physics_component.h"

namespace elsa {
    namespace components {

        const float VELOCITY = 100;

        void InputComponent::init()
        {
            physics_component_ = entity->get_component<PhysicsComponent>();

            input::InputManager::register_callback(input::InputEvent::Left_Up, std::bind(&InputComponent::handle_left_up_event, this, std::placeholders::_1));
            input::InputManager::register_callback(input::InputEvent::Left_Down, std::bind(&InputComponent::handle_left_down_event, this, std::placeholders::_1));
            input::InputManager::register_callback(input::InputEvent::Right_Up, std::bind(&InputComponent::handle_right_up_event, this, std::placeholders::_1));
            input::InputManager::register_callback(input::InputEvent::Right_Down, std::bind(&InputComponent::handle_right_down_event, this, std::placeholders::_1));
        }

        void InputComponent::handle_left_up_event(float dt)
        {
            physics_component_->velocity.x = 0;
        }

        void InputComponent::handle_left_down_event(float dt)
        {
            physics_component_->velocity.x = -VELOCITY;
        }

        void InputComponent::handle_right_up_event(float dt)
        {
            physics_component_->velocity.x = 0;
        }

        void InputComponent::handle_right_down_event(float dt)
        {
            physics_component_->velocity.x = VELOCITY;
        }
    }
}
