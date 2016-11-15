#pragma once

#include "renderable_component.h"

#include "../typedef.h"
#include "../entities/entity.h"
#include "../rendering/renderer2d.h"

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
            renderer_->render_texture(texture_.get(), static_cast<i32>(position.x), static_cast<i32>(position.y));
        }
    }
}