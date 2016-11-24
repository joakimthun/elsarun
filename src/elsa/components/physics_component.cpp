#include "physics_component.h"

#include <iostream>

#include "../entities/entity.h"
#include "../entities/entity_manager.h"
#include "transform_component.h"

namespace elsa {
    namespace components {

        PhysicsComponent::PhysicsComponent(const math::Vector2D& gravity, u32 width, u32 height)
            :
            gravity(gravity),
            body(std::make_unique<physics::AABB>(0, 0, width, height))
        {
        }

        void PhysicsComponent::init()
        {
            update_body();
        }

        void PhysicsComponent::update(float dt)
        {
            velocity.lerp(velocity_goal, dt * 1000);

            auto old_position = entity->transform.position;

            auto update_vector = velocity + gravity;

            // X
            entity->transform.position.x += (update_vector.x * dt);
            update_body();

            if (entity->entity_manager_->resolve_collisions(*body))
            {
                reset_body(old_position);
                entity->transform.position.x = old_position.x;
            }

            // Y
            entity->transform.position.y += (update_vector.y * dt);
            update_body();

            if (entity->entity_manager_->resolve_collisions(*body))
            {
                reset_body(old_position);
                entity->transform.position.y = old_position.y;

                if (velocity.y >= 0)
                {
                    entity->emit(entities::EntityEvent::OnTheGround);
                }
            }
        }

        ComponentType PhysicsComponent::type()
        {
            return ComponentType::PhysicsComponent;
        }

        void PhysicsComponent::reset_body(const math::Vector2D& old_position)
        {
            body->x = static_cast<u32>(old_position.x);
            body->y = static_cast<u32>(old_position.y);
        }

        void PhysicsComponent::update_body()
        {
            body->x = static_cast<u32>(entity->transform.position.x);
            body->y = static_cast<u32>(entity->transform.position.y);
        }

    }
}
