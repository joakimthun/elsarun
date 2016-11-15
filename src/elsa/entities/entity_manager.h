#pragma once

#include <memory>
#include <vector>

#include "entity.h"

namespace elsa {
    namespace entities {

        class EntityManager
        {
        public:
            EntityManager();
            ~EntityManager();

            Entity* create_entity();
            void init();
            void frame(float dt);
        private:
            std::vector<std::unique_ptr<Entity>> entities_;
        };
    }
}
