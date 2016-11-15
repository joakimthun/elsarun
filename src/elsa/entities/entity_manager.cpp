#include "entity_manager.h"

#include <iostream>

#include "entity.h"
#include "../components/input_component.h"
#include "../components/renderable_component.h"

namespace elsa {
    namespace entities {

        EntityManager::EntityManager() {}
        EntityManager::~EntityManager() {}

        Entity* EntityManager::create_entity()
        {
            entities_.push_back(std::make_unique<Entity>());
            return entities_.back().get();
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
    }
}
