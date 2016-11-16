#pragma once

#include "renderable_rect_component.h"

#include "../entities/entity.h"
#include "../rendering/renderer2d.h"

namespace elsa {
    namespace components {

        RenderableRectComponent::RenderableRectComponent(rendering::Renderer2D* renderer, rendering::Color color, i32 width, i32 height)
            :
            renderer_(renderer),
            color_(color),
            width_(width),
            height_(height)
        {
        }

        void RenderableRectComponent::render()
        {
            const auto position = entity->transform.position;

            renderer_->set_draw_color(color_);
            renderer_->fill_rect(static_cast<i32>(position.x), static_cast<i32>(position.y), width_, height_);
        }

        ComponentType RenderableRectComponent::type()
        {
            return ComponentType::RenderableRectComponent;
        }
    }
}