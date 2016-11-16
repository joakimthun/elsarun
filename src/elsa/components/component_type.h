#pragma once

#include <cstddef>

#include "../typedef.h"

namespace elsa {
    namespace components {

        enum class ComponentType : u16
        {
            TransformComponent,
            PhysicsComponent,
            ElsaAiComponent,
            InputComponent,
            RenderableComponent,
            RenderableRectComponent,
            LeashComponent,
            MAX_VALUE
        };

        inline std::size_t constexpr max_num_component_types()
        {
            return static_cast<std::size_t>(ComponentType::MAX_VALUE);
        }

    }
}