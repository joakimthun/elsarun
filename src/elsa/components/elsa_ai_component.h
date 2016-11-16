#pragma once

#include <array>

#include "../typedef.h"
#include "component.h"

namespace elsa {
    namespace components {

        struct PhysicsComponent;

        struct ElsaAiComponent : Component
        {
            void init() override;
            void update(float dt) override;
            ComponentType type() override;

        private:
            PhysicsComponent* physics_component_ = nullptr;
        };

    }
}
