#pragma once

#include "component.h"

namespace elsa {
    namespace components {

        struct PhysicsComponent;

        struct InputComponent : Component
        {
            void init() override;
        private:
            void handle_left_up_event();
            void handle_left_down_event();
            void handle_right_up_event();
            void handle_right_down_event();
            void handle_up_up_event();
            void handle_up_down_event();
            void handle_down_up_event();
            void handle_down_down_event();

            PhysicsComponent* physics_component_ = nullptr;
        };

    }
}
