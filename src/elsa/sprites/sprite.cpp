#include "sprite.h"

#include "../rendering/renderer2d.h"

namespace elsa {
    namespace sprites {

        Sprite::Sprite(std::unique_ptr<rendering::Texture> texture, float frame_time)
            :
            texture_(std::move(texture)),
            frame_time_(frame_time),
            num_frames_(0),
            current_frame_index_(0),
            current_frame_time_(0.0f)
        {
        }

        void Sprite::update(float dt)
        {
            current_frame_time_ += dt;

            if (current_frame_time_ >= frame_time_)
            {
                current_frame_time_ = 0;
                current_frame_index_++;

                // Reset the frame index when we have cycled through all frames
                if (current_frame_index_ >= num_frames_)
                {
                    current_frame_index_ = 0;
                }
            }
        }

        void Sprite::render(rendering::Renderer2D* renderer, i32 x, i32 y)
        {
            const auto& current_frame = frames_[current_frame_index_];
            renderer->render_texture(texture_.get(), x, y, current_frame.x, current_frame.y, current_frame.width, current_frame.height);
        }

        void Sprite::add_frame(u32 x, u32 y, u32 width, u32 height)
        {
            frames_.push_back(sprites::SpriteFrame{ x, y, width, height });
            num_frames_++;
        }
    }
}