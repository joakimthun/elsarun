#include "leash_component.h"

#include "../rendering/renderer2d.h"
#include "../entities/entity.h"
#include "physics_component.h"

#include <iostream>

namespace elsa {
    namespace components {

        auto const LEASH_FORCE = 0.8f;

        LeashComponent::LeashComponent(rendering::Renderer2D* renderer, entities::Entity* slave, rendering::Color color)
            :
            renderer_(renderer),
            slave_(slave),
            color_(color)
        {
        }

        void LeashComponent::init()
        {
            slave_physics_component_ = slave_->get_component<PhysicsComponent>(ComponentType::PhysicsComponent);
        }

        void LeashComponent::update(float dt)
        {
            auto master_position = entity->transform.position;
            auto slave_position = slave_->transform.position;

            auto master_direction = master_position - slave_position;

            slave_physics_component_->velocity += (master_direction * LEASH_FORCE);

            static int fc = 0;

            if (fc % 1000 == 0)
            {
                std::cout << "x: " << master_direction.x << ", y: " << master_direction.y << std::endl;
            }

            fc++;
        }

        void LeashComponent::render()
        {
            auto master_position = entity->transform.position;
            auto slave_position = slave_->transform.position;

            renderer_->set_draw_color(color_);
            renderer_->render_line(static_cast<i32>(master_position.x), static_cast<i32>(master_position.y), static_cast<i32>(slave_position.x), static_cast<i32>(slave_position.y));
        }

        ComponentType LeashComponent::type()
        {
            return ComponentType::LeashComponent;
        }

    }
}
