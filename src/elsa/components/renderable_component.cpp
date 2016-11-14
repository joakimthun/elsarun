#pragma once

#include "renderable_component.h"

#include "../rendering/renderer.h"

namespace elsa {
    namespace components {

        RenderableComponent::RenderableComponent(rendering::Renderer* renderer, std::unique_ptr<rendering::Texture> texture)
            :
            renderer_(renderer),
            texture_(std::move(texture))
        {
        }

        void RenderableComponent::render()
        {
            renderer_->render_texture(texture_.get());
        }
    }
}