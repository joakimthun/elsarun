#pragma once

#include <memory>

#include "component.h"
#include "../math/vector2D.h"
#include "../physics/aabb.h"

namespace elsa {
    namespace components {

        struct PhysicsComponent : Component
        {
            PhysicsComponent(math::Vector2D& gravity, u32 width, u32 height);

            void init() override;
            void update(float dt) override;
            ComponentType type() override;

            math::Vector2D velocity;
            math::Vector2D velocity_goal;
            math::Vector2D gravity;
            std::unique_ptr<physics::AABB> body;

        private:
            void update_body();
        };

    }
}
