#pragma once

#include <array>
#include <memory>
#include <bitset>

#include "../components/component.h"

namespace elsa {
    namespace entities {

        inline std::size_t get_unique_component_id()
        {
            static std::size_t last_id{ 0u };
            return last_id++;
        }

        template <typename TComponent>
        inline std::size_t get_component_type_id()
        {
            static_assert(std::is_base_of<components::Component, TComponent>::value, "TComponent must inherit from Component");

            // Every time we call this function with a specific type `T`,
            // we are actually calling an instantiation of this template,
            // with its own unique static `typeID` variable.

            // Upon calling this function for the first time with a specific
            // type `T1`, `typeID` will be initialized with an unique ID.
            // Subsequent calls with the same type `T1` will return the
            // same ID.

            static std::size_t type_id{ get_unique_component_id() };
            return type_id;
        }

        const std::size_t NumComponents = 50;

        class Entity
        {
        public:
            template<typename TComponent>
            inline bool has_component() const 
            {
                return component_flags_[get_component_type_id<TComponent>()];
            }

            template<typename TComponent>
            inline TComponent* get_component()
            {
                return static_cast<TComponent*>(components_[get_component_type_id<TComponent>()].get());
            }

            template <typename TComponent, typename... TArgs>
            void add_component(TArgs&&... args)
            {
                auto c = std::make_unique<TComponent>(std::forward<TArgs>(args)...);

                c->entity = this;
                c->init();

                components_[get_component_type_id<TComponent>()] = std::move(c);
                component_flags_[get_component_type_id<TComponent>()] = true;
            }


        private:
            std::bitset<NumComponents> component_flags_;
            std::array<std::unique_ptr<components::Component>, NumComponents> components_;
        };
    }
}