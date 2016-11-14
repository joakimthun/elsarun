#pragma once

#include <iostream>

#include "component.h"

namespace elsa {
    namespace components {

        struct InputComponent : Component
        {
            void update(float dt) override
            {
                std::cout << "InputComponent -> update" << std::endl;
            };
        };

    }
}
