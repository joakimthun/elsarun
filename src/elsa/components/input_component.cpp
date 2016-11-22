#include "input_component.h"

#include "../input/input_manager.h"
#include "../entities/entity.h"
#include "physics_component.h"

namespace elsa {
    namespace components {

        const float VELOCITY = 300;

        void InputComponent::init()
        {
            physics_component_ = entity->get_component<PhysicsComponent>(ComponentType::PhysicsComponent);

            input::InputManager::register_callback(input::InputEvent::Left_Up, [this]() { set_state_up(Key::Left); });
            input::InputManager::register_callback(input::InputEvent::Left_Down, [this]() { set_state_down(Key::Left); });
            input::InputManager::register_callback(input::InputEvent::Right_Up, [this]() { set_state_up(Key::Right); });
            input::InputManager::register_callback(input::InputEvent::Right_Down, [this]() { set_state_down(Key::Right); });
            
            input::InputManager::register_callback(input::InputEvent::Up_Up, [this]() { set_state_up(Key::Up); });
            input::InputManager::register_callback(input::InputEvent::Up_Down, [this]() { set_state_down(Key::Up); });
            input::InputManager::register_callback(input::InputEvent::Down_Up, [this]() { set_state_up(Key::Down); });
            input::InputManager::register_callback(input::InputEvent::Down_Down, [this]() { set_state_down(Key::Down); });
        }

        void InputComponent::update(float dt)
        {
            if (is_down(Key::Up))
            {
                physics_component_->velocity_goal.y = -VELOCITY;
            }
            else if (is_down(Key::Down))
            {
                physics_component_->velocity_goal.y = VELOCITY;
            }
            else
            {
                physics_component_->velocity_goal.y = 0;
            }

            if (is_down(Key::Left))
            {
                physics_component_->velocity_goal.x = -VELOCITY;
            }
            else if (is_down(Key::Right))
            {
                physics_component_->velocity_goal.x = VELOCITY;
            }
            else
            {
                physics_component_->velocity_goal.x = 0;
            }
        }

        ComponentType InputComponent::type()
        {
            return ComponentType::InputComponent;
        }

        void InputComponent::set_state_down(Key k)
        {
            key_states_[static_cast<std::size_t>(k)] = true;
        }

        void InputComponent::set_state_up(Key k)
        {
            key_states_[static_cast<std::size_t>(k)] = false;
        }

        bool InputComponent::is_down(Key k)
        {
            return key_states_[static_cast<std::size_t>(k)];
        }
    }
}
