#include "physics_component.h"

#include "../entities/entity.h"
#include "transform_component.h"

#include <iostream>

namespace elsa {
    namespace components {

        void PhysicsComponent::update(float dt)
        {
            entity->transform.position.x += (velocity.x * dt);
            entity->transform.position.y += (velocity.y * dt);

            //std::cout << "position.x: " << entity->transform.position.x << std::endl;
            //std::cout << "position.y: " << entity->transform.position.y << std::endl;
            //std::cout << "velocity.x: " << velocity.x << std::endl;
            //std::cout << "velocity.y: " << velocity.y << std::endl;
        }

    }
}
