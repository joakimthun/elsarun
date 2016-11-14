#pragma once

#include <memory>

#include "component.h"
#include "../rendering/texture.h"

namespace elsa {

    namespace rendering {
        class Renderer;
    }

    namespace components {

        class RenderableComponent : public Component
        {
        public:
            RenderableComponent(rendering::Renderer* renderer, std::unique_ptr<rendering::Texture> texture);
            void render() override;

        private:
            rendering::Renderer* renderer_;
            std::unique_ptr<rendering::Texture> texture_;
        };

    }
}