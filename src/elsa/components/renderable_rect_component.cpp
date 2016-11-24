#pragma once

#include "renderable_rect_component.h"

#include "../entities/entity.h"
#include "../rendering/renderer2d.h"
#include "physics_component.h"

namespace elsa {
    namespace components {

        RenderableRectComponent::RenderableRectComponent(rendering::Renderer2D* renderer, rendering::Color color, i32 width, i32 height, bool render_body)
            :
            renderer_(renderer),
            color_(color),
            width_(width),
            height_(height),
            render_body_(render_body),
            body_(nullptr)
        {
        }

        void RenderableRectComponent::init()
        {
            auto physics_component = entity->get_component<PhysicsComponent>(ComponentType::PhysicsComponent);
            if (physics_component != nullptr)
            {
                body_ = physics_component->body.get();
            }
        }

        void RenderableRectComponent::render()
        {
            const auto position = entity->transform.position;

            renderer_->set_draw_color(color_);
            renderer_->fill_rect(static_cast<i32>(position.x), static_cast<i32>(position.y), width_, height_);

            if (render_body_ && body_ != nullptr)
            {
                renderer_->set_draw_color(rendering::Color::create(255, 0, 0));
                renderer_->draw_rect(body_->x, body_->y, body_->width, body_->height);
            }
        }

        ComponentType RenderableRectComponent::type()
        {
            return ComponentType::RenderableRectComponent;
        }
    }
}