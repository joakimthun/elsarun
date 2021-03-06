#pragma once

#include <memory>

#include "../typedef.h"
#include "component.h"
#include "../rendering/color.h"

namespace elsa {

    namespace rendering {
        class Renderer2D;
    }

    namespace physics {
        struct AABB;
    }

    namespace components {

        class RenderableRectComponent : public Component
        {
        public:
            RenderableRectComponent(rendering::Renderer2D* renderer, rendering::Color color, i32 width, i32 height, bool render_body);
            void init() override;
            void render() override;
            ComponentType type() override;

        private:
            rendering::Renderer2D* renderer_;
            rendering::Color color_;
            i32 width_; 
            i32 height_;
            bool render_body_;
            const physics::AABB* body_;
        };

    }
}