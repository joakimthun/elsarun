#include "input_component.h"

#include "../entities/entity.h"
#include "../input/input_manager.h"
#include "physics_component.h"

namespace elsa {
    namespace components {

        const float VELOCITY = 300;

        void InputComponent::init()
        {
            physics_component_ = entity->get_component<PhysicsComponent>();

            input::InputManager::register_callback(input::InputEvent::Left_Up, std::bind(&InputComponent::handle_left_up_event, this));
            input::InputManager::register_callback(input::InputEvent::Left_Down, std::bind(&InputComponent::handle_left_down_event, this));
            input::InputManager::register_callback(input::InputEvent::Right_Up, std::bind(&InputComponent::handle_right_up_event, this));
            input::InputManager::register_callback(input::InputEvent::Right_Down, std::bind(&InputComponent::handle_right_down_event, this));

            input::InputManager::register_callback(input::InputEvent::Up_Up, std::bind(&InputComponent::handle_up_up_event, this));
            input::InputManager::register_callback(input::InputEvent::Up_Down, std::bind(&InputComponent::handle_up_down_event, this));
            input::InputManager::register_callback(input::InputEvent::Down_Up, std::bind(&InputComponent::handle_down_up_event, this));
            input::InputManager::register_callback(input::InputEvent::Down_Down, std::bind(&InputComponent::handle_down_down_event, this));
        }

        void InputComponent::handle_left_up_event()
        {
            physics_component_->velocity.x = 0;
        }

        void InputComponent::handle_left_down_event()
        {
            physics_component_->velocity.x = -VELOCITY;
        }

        void InputComponent::handle_right_up_event()
        {
            physics_component_->velocity.x = 0;
        }

        void InputComponent::handle_right_down_event()
        {
            physics_component_->velocity.x = VELOCITY;
        }

        void InputComponent::handle_up_up_event()
        {
            physics_component_->velocity.y = 0;
        }

        void InputComponent::handle_up_down_event()
        {
            physics_component_->velocity.y = -VELOCITY;
        }

        void InputComponent::handle_down_up_event()
        {
            physics_component_->velocity.y = 0;
        }

        void InputComponent::handle_down_down_event()
        {
            physics_component_->velocity.y = VELOCITY;
        }
    }
}
