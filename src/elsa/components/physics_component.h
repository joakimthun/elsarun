#pragma once

#include "component.h"
#include "../math/vector2D.h"

namespace elsa {
    namespace components {

        struct PhysicsComponent : Component
        {
            math::Vector2D velocity;
        };

    }
}
