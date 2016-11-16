#pragma once

#include <array>

#include "../typedef.h"
#include "component.h"

namespace elsa {
    namespace components {

        struct PhysicsComponent;

        enum class Key : u16
        {
            Left,
            Right,
            Up,
            Down,
            MAX_VALUE
        };

        inline std::size_t constexpr max_num_keys()
        {
            return static_cast<std::size_t>(Key::MAX_VALUE);
        }

        struct InputComponent : Component
        {
            void init() override;
            void update(float dt) override;
            ComponentType type() override;

        private:
            void set_state_down(Key k);
            void set_state_up(Key k);
            bool is_down(Key k);

            PhysicsComponent* physics_component_ = nullptr;
            std::array<bool, max_num_keys()> key_states_ = { false };
        };

    }
}
