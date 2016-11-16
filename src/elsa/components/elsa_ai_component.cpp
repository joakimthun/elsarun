#include "elsa_ai_component.h"

#include "../entities/entity.h"
#include "physics_component.h"

namespace elsa {
    namespace components {

        void ElsaAiComponent::init()
        {
            physics_component_ = entity->get_component<PhysicsComponent>(ComponentType::PhysicsComponent);
        }

        void ElsaAiComponent::update(float dt)
        {
        }

        ComponentType ElsaAiComponent::type()
        {
            return ComponentType::ElsaAiComponent;
        }

    }
}
