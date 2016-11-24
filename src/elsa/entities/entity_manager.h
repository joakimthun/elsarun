#pragma once

#include <memory>
#include <vector>

#include "entity.h"

namespace elsa {
    namespace tiles {
        class TileMap;
    }

    namespace physics {
        struct AABB;
    }

    namespace entities {

        class EntityManager
        {
        public:
            EntityManager(const tiles::TileMap* tile_map);
            ~EntityManager();

            Entity* create_entity();
            void init();
            void frame(float dt);
            bool resolve_collisions(const physics::AABB& entity_aabb);

        private:
            std::vector<std::unique_ptr<Entity>> entities_;
            const tiles::TileMap* tile_map_;
        };
    }
}
