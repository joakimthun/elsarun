#include "entity_manager.h"

#include <iostream>

#include "entity.h"
#include "../components/input_component.h"
#include "../components/renderable_component.h"

namespace elsa {
    namespace entities {

        EntityManager::EntityManager()
        {
            auto e = new entities::Entity();
            

            std::cout << "get_component_type_id InputComponent:" << entities::get_component_type_id<components::InputComponent>() << std::endl;
            std::cout << "get_component_type_id InputComponent:" << entities::get_component_type_id<components::InputComponent>() << std::endl;
            std::cout << "get_component_type_id RenderableComponent:" << entities::get_component_type_id<components::RenderableComponent>() << std::endl;
            std::cout << "get_component_type_id InputComponent:" << entities::get_component_type_id<components::InputComponent>() << std::endl;

            std::cout << "has_component InputComponent:" << (e->has_component<components::InputComponent>() ? "true" : "false") << std::endl;

            e->add_component<components::InputComponent>();

            std::cout << "has_component InputComponent:" << (e->has_component<components::InputComponent>() ? "true" : "false") << std::endl;


            std::cout << "has_component RenderableComponent:" << (e->has_component<components::RenderableComponent>() ? "true" : "false") << std::endl;

            e->add_component<components::RenderableComponent>();

            std::cout << "has_component RenderableComponent:" << (e->has_component<components::RenderableComponent>() ? "true" : "false") << std::endl;

        }
    }
}
