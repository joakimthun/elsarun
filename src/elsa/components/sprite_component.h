#pragma once

#include <memory>

#include "../typedef.h"
#include "component.h"
#include "../rendering/color.h"
#include "../sprites/sprite.h"

namespace elsa {

    namespace rendering {
        class Renderer2D;
    }

    namespace physics {
        struct AABB;
    }

    namespace components {

        class SpriteComponent : public Component
        {
        public:
            SpriteComponent(rendering::Renderer2D* renderer, std::unique_ptr<sprites::Sprite> sprite, bool render_body);
            void init() override;
            void render() override;
            ComponentType type() override;

        private:
            rendering::Renderer2D* renderer_;
            std::unique_ptr<sprites::Sprite> sprite_;
            bool render_body_;
            const physics::AABB* body_;
        };

    }
}