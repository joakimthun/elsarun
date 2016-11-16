#include "elsa_ai_component.h"

#include "../entities/entity.h"
#include "physics_component.h"

namespace elsa {
    namespace components {

        const float VELOCITY = 300;

        ElsaAiComponent::ElsaAiComponent(i32 max_x, i32 min_x, i32 max_y, i32 min_y)
            :
            max_x_(max_x),
            min_x_(min_x),
            max_y_(max_y),
            min_y_(min_y)
        {
        }

        void ElsaAiComponent::init()
        {
            physics_component_ = entity->get_component<PhysicsComponent>(ComponentType::PhysicsComponent);
        }

        void ElsaAiComponent::update(float dt)
        {
            if (!started_)
            {
                started_ = true;
                physics_component_->velocity.x = -VELOCITY;
                return;
            }

            if(entity->transform.position.x <= min_x_)
                physics_component_->velocity.x = VELOCITY;
            else if(entity->transform.position.x >= max_x_)
                physics_component_->velocity.x = -VELOCITY;

        }

        ComponentType ElsaAiComponent::type()
        {
            return ComponentType::ElsaAiComponent;
        }

    }
}
