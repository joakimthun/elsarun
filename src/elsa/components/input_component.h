#pragma once

#include "component.h"

namespace elsa {
    namespace components {

        struct PhysicsComponent;

        struct InputComponent : Component
        {
            void init() override;
        private:
            void handle_left_up_event(float dt);
            void handle_left_down_event(float dt);
            void handle_right_up_event(float dt);
            void handle_right_down_event(float dt);

            PhysicsComponent* physics_component_ = nullptr;
        };

    }
}
