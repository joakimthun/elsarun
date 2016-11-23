#include "physics_component.h"

#include "../entities/entity.h"
#include "transform_component.h"

namespace elsa {
    namespace components {

        PhysicsComponent::PhysicsComponent(math::Vector2D& gravity, u32 width, u32 height)
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
            velocity.lerp(velocity_goal, dt * 100);

            entity->transform.position += (velocity * dt);
            entity->transform.position += (gravity * dt);

            update_body();
        }

        ComponentType PhysicsComponent::type()
        {
            return ComponentType::PhysicsComponent;
        }

        void PhysicsComponent::update_body()
        {
            body->x = static_cast<u32>(entity->transform.position.x);
            body->y = static_cast<u32>(entity->transform.position.y);
        }

    }
}
