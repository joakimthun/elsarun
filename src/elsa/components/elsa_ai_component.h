#pragma once

#include <array>

#include "../typedef.h"
#include "component.h"

namespace elsa {
    namespace components {

        struct PhysicsComponent;

        struct ElsaAiComponent : Component
        {
            ElsaAiComponent(i32 max_x, i32 min_x, i32 max_y, i32 min_y);
            void init() override;
            void update(float dt) override;
            ComponentType type() override;

        private:
            PhysicsComponent* physics_component_ = nullptr;
            i32 max_x_;
            i32 min_x_;
            i32 max_y_;
            i32 min_y_;
            bool started_ = false;
        };

    }
}
