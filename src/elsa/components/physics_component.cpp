#include "physics_component.h"

#include "../entities/entity.h"
#include "transform_component.h"

namespace elsa {
    namespace components {

        PhysicsComponent::PhysicsComponent(math::Vector2D& gravity)
            :
            gravity(gravity)
        {
        }

        void PhysicsComponent::update(float dt)
        {
            velocity.lerp(velocity_goal, dt * 100);

            entity->transform.position += (velocity * dt);
            entity->transform.position += (gravity * dt);
        }

        ComponentType PhysicsComponent::type()
        {
            return ComponentType::PhysicsComponent;
        }

    }
}
