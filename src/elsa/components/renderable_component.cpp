#pragma once

#include "renderable_component.h"

#include "../typedef.h"
#include "../entities/entity.h"
#include "../rendering/renderer2d.h"
#include "../rendering/color.h"

namespace elsa {
    namespace components {

        RenderableComponent::RenderableComponent(rendering::Renderer2D* renderer, std::unique_ptr<rendering::Texture> texture)
            :
            renderer_(renderer),
            texture_(std::move(texture))
        {
        }

        void RenderableComponent::render()
        {
            const auto position = entity->transform.position;
            //renderer_->render_texture(texture_.get(), static_cast<i32>(position.x), static_cast<i32>(position.y));

            renderer_->set_draw_color(rendering::Color::create(255, 0, 0));
            renderer_->fill_rect(static_cast<i32>(position.x), static_cast<i32>(position.y), 50, 50);
        }
        ComponentType RenderableComponent::type()
        {
            return ComponentType::RenderableComponent;
        }
    }
}