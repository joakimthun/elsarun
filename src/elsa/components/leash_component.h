#pragma once

#include <array>

#include "../typedef.h"
#include "component.h"
#include "../rendering/color.h"

namespace elsa {

    namespace entities {
        class Entity;
    }

    namespace rendering {
        class Renderer2D;
    }

    namespace components {

        struct PhysicsComponent;

        struct LeashComponent : Component
        {
            LeashComponent(rendering::Renderer2D* renderer, entities::Entity* slave, rendering::Color color);
            void init() override;
            void update(float dt) override;
            void render() override;
            ComponentType type() override;

        private:
            rendering::Renderer2D* renderer_; 
            entities::Entity* slave_;
            rendering::Color color_;
            PhysicsComponent* slave_physics_component_ = nullptr;
        };

    }
}
