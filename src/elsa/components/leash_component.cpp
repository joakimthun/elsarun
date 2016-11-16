#include "leash_component.h"

#include "../rendering/renderer2d.h"
#include "../entities/entity.h"

namespace elsa {
    namespace components {

        LeashComponent::LeashComponent(rendering::Renderer2D* renderer, entities::Entity* slave, rendering::Color color)
            :
            renderer_(renderer),
            slave_(slave),
            color_(color)
        {
        }

        void LeashComponent::update(float dt)
        {
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
