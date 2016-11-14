#pragma once

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

            entities::Entity* entity;
        };

    }
}
