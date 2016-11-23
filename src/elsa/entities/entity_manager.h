#pragma once

#include <memory>
#include <vector>

#include "entity.h"
//#include ""

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
            //void resolve_collisions(const Entity* entity);

        private:
            std::vector<std::unique_ptr<Entity>> entities_;
        };
    }
}
