#pragma once

#include "sprite_component.h"

#include "../entities/entity.h"
#include "../rendering/renderer2d.h"
#include "physics_component.h"

namespace elsa {
    namespace components {

        SpriteComponent::SpriteComponent(rendering::Renderer2D* renderer, std::unique_ptr<sprites::Sprite> sprite, bool render_body)
            :
            renderer_(renderer),
            sprite_(std::move(sprite)),
            render_body_(render_body),
            body_(nullptr)
        {
        }

        void SpriteComponent::init()
        {
            auto physics_component = entity->get_component<PhysicsComponent>(ComponentType::PhysicsComponent);
            if (physics_component != nullptr)
            {
                body_ = physics_component->body.get();
            }
        }

        void SpriteComponent::render()
        {
            const auto position = entity->transform.position;

            //renderer_->set_draw_color(color_);
            //renderer_->fill_rect(static_cast<i32>(position.x), static_cast<i32>(position.y), width_, height_);

            if (render_body_ && body_ != nullptr)
            {
                renderer_->set_draw_color(rendering::Color::create(255, 0, 0));
                renderer_->draw_rect(body_->x, body_->y, body_->width, body_->height);
            }
        }

        ComponentType SpriteComponent::type()
        {
            return ComponentType::SpriteComponent;
        }
    }
}