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
            entity->transform.position.x += (velocity.x * dt);
            entity->transform.position.y += (velocity.y * dt);
            entity->transform.position.x += (gravity.x * dt);
            entity->transform.position.y += (gravity.y * dt);
        }

        ComponentType PhysicsComponent::type()
        {
            return ComponentType::PhysicsComponent;
        }

    }
}
