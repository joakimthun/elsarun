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

        void EntityManager::update(float dt)
        {
            for (auto& c : entities_) c->update(dt);
        }

        void EntityManager::render()
        {
            for (auto& c : entities_) c->render();
        }
    }
}
