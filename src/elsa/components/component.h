#pragma once

#include "component_type.h"

namespace elsa {

    namespace entities {
        class Entity;
    }

    namespace components {

        struct Component
        {
            virtual ~Component() {};
            virtual void init() {};
            virtual void update(float dt) {};
            virtual void render() {};
            virtual ComponentType type() = 0;

            entities::Entity* entity;
        };

    }
}
