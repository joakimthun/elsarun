#pragma once

#include <iostream>

#include "component.h"
#include "../math/vector2D.h"

namespace elsa {
    namespace components {

        struct TransformComponent : Component
        {
            math::Vector2D position;
            math::Vector2D rotation;
            math::Vector2D scale;

            void update(float dt) override
            {
                std::cout << "TransformComponent -> update" << std::endl;
            };
        };

    }
}
