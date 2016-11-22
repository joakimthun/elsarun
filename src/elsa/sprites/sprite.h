#pragma once

#include <vector>
#include <memory>

#include "../typedef.h"
#include "../rendering/texture.h"

namespace elsa {

    namespace rendering {
        Renderer2D;
    }

    namespace sprites {

        struct SpriteFrame
        {
            u32 x;
            u32 y;
            u32 width;
            u32 height;
        };

        class Sprite
        {
        public:
            Sprite(std::unique_ptr<rendering::Texture> texture, float frame_time);
            void update(float dt);
            void render(rendering::Renderer2D* renderer, i32 x, i32 y);
            void add_frame(u32 x, u32 y, u32 width, u32 height);

        private:
            float frame_time_;
            std::vector<SpriteFrame> frames_;
            std::size_t num_frames_;
            std::unique_ptr<rendering::Texture> texture_;
            std::size_t current_frame_index_;
            float current_frame_time_;
        };

    }
}