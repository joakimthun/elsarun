#pragma once

#include "component.h"
#include "../math/vector2D.h"

namespace elsa {
    namespace components {

        struct PhysicsComponent : Component
        {
            void update(float dt) override;
            math::Vector2D velocity;
        };

    }
}
