#include "entity_manager.h"

#include <iostream>

#include "entity.h"
#include "../tiles/tile_map.h"
#include "../components/physics_component.h"

namespace elsa {
    namespace entities {

        EntityManager::EntityManager(const tiles::TileMap* tile_map) 
            :
            tile_map_(tile_map)
        {}

        EntityManager::~EntityManager() {}

        Entity* EntityManager::create_entity()
        {
            entities_.push_back(std::make_unique<Entity>());
            auto entity = entities_.back().get();

            entity->entity_manager_ = this;

            return entity;
        }

        void EntityManager::init()
        {
            for (auto& e : entities_)
            {
                e->init();
            }
        }

        void EntityManager::frame(float dt)
        {
            for (auto& e : entities_)
            {
                e->frame(dt);
            }
        }

        bool EntityManager::resolve_collisions(const physics::AABB& entity_aabb)
        {
            for (const auto& layer : tile_map_->layers)
            {
                for (const auto& tile_aabb : layer.collidable_tiles)
                {
                    if (tile_aabb.intersects(entity_aabb))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    }
}
