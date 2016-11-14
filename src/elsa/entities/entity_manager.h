#pragma once

#include <memory>
#include <vector>

namespace elsa {
    namespace entities {

        class EntityManager
        {
        public:
            EntityManager();
            ~EntityManager() {};

        private:
            //std::vector<std::unique_ptr<Entity<50>>> entities_;
        };
    }
}
