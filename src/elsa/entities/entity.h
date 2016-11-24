#pragma once

#include <array>
#include <vector>
#include <memory>
#include <bitset>

#include "entity_events.h"
#include "../components/component.h"
#include "../components/transform_component.h"

namespace elsa {
    namespace entities {

        class EntityManager;

        inline std::size_t constexpr get_component_type_index(components::ComponentType component_type)
        {
            return static_cast<std::size_t>(component_type);
        }

        class Entity
        {
        public:
            inline bool has_component(components::ComponentType component_type) const
            {
                return component_flags_[get_component_type_index(component_type)];
            }

            template<typename TComponent>
            inline TComponent* get_component(components::ComponentType component_type) const
            {
                static_assert(std::is_base_of<components::Component, TComponent>::value, "TComponent must inherit from Component");

                return static_cast<TComponent*>(components_[get_component_type_index(component_type)].get());
            }

            template <typename TComponent, typename... TArgs>
            inline void add_component(TArgs&&... args)
            {
                static_assert(std::is_base_of<components::Component, TComponent>::value, "TComponent must inherit from Component");

                auto c = std::make_unique<TComponent>(std::forward<TArgs>(args)...);

                c->entity = this;
                auto component_type_index = get_component_type_index(c->type());

                added_components_.push_back(c.get());

                components_[component_type_index] = std::move(c);
                component_flags_[component_type_index] = true;
            }

            inline void init()
            {
                for (auto c : added_components_)
                {
                    c->init();
                }
            };

            inline void frame(float dt)
            {
                for (auto c : added_components_)
                {
                    c->update(dt);
                    c->render();
                }
            };

            inline void emit(EntityEvent event)
            {
                for (auto c : added_components_)
                {
                    c->listen(event);
                }
            };

            components::TransformComponent transform;
            EntityManager* entity_manager_;
        private:
            std::bitset<components::max_num_component_types()> component_flags_;
            std::array<std::unique_ptr<components::Component>, components::max_num_component_types()> components_;
            std::vector<components::Component*> added_components_;
        };
    }
}