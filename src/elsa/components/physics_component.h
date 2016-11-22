#pragma once

#include "component.h"
#include "../math/vector2D.h"

namespace elsa {
    namespace components {

        struct PhysicsComponent : Component
        {
            PhysicsComponent(math::Vector2D& gravity);

            void update(float dt) override;
            ComponentType type() override;

            math::Vector2D velocity;
            math::Vector2D velocity_goal;
            math::Vector2D gravity;
        };

    }
}
