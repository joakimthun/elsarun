#include "input_component.h"

#include "../input/input_manager.h"
#include "../entities/entity.h"
#include "physics_component.h"

namespace elsa {
    namespace components {

        const float VELOCITY = 500;
        const float JUMP_VELOCITY = 1200;

        void InputComponent::init()
        {
            physics_component_ = entity->get_component<PhysicsComponent>(ComponentType::PhysicsComponent);

            input::InputManager::register_callback(input::InputEvent::Left_Up, [this]() { set_state_up(Key::Left); });
            input::InputManager::register_callback(input::InputEvent::Left_Down, [this]() { set_state_down(Key::Left); });
            input::InputManager::register_callback(input::InputEvent::Right_Up, [this]() { set_state_up(Key::Right); });
            input::InputManager::register_callback(input::InputEvent::Right_Down, [this]() { set_state_down(Key::Right); });
            
            input::InputManager::register_callback(input::InputEvent::Up_Down, std::bind(&InputComponent::jump, this));
            input::InputManager::register_callback(input::InputEvent::Down_Up, [this]() { set_state_up(Key::Down); });
            input::InputManager::register_callback(input::InputEvent::Down_Down, [this]() { set_state_down(Key::Down); });
        }

        void InputComponent::update(float dt)
        {
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

        void InputComponent::listen(entities::EntityEvent event)
        {
            if (event == entities::EntityEvent::OnTheGround)
            {
                jumping_state_ = JumpingState::Gounded;
            }
        }

        void InputComponent::jump()
        {
            if (jumping_state_ == JumpingState::Gounded)
            {
                jumping_state_ = JumpingState::Jumping;
                physics_component_->velocity.y = -JUMP_VELOCITY;
            }
            else if (jumping_state_ == JumpingState::Jumping)
            {
                jumping_state_ = JumpingState::DoubleJumping;
                physics_component_->velocity.y = -JUMP_VELOCITY;
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
