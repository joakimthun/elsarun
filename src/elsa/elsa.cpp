#include <SDL.h>
#include <iostream>

#include "errors/elsa_exception.h"
#include "rendering/window.h"
#include "rendering/renderer2d.h"
#include "rendering/texture.h"
#include "rendering/color.h"
#include "timing/timer.h"

#include "input/input_manager.h"
#include "entities/entity.h"
#include "entities/entity_manager.h"
#include "components/input_component.h"
#include "components/renderable_component.h"
#include "components/physics_component.h"

using namespace elsa;

auto const SCREEN_WIDTH = 800;
auto const SCREEN_HEIGHT = 600;

void setup_entities(entities::EntityManager& em, rendering::Renderer2D* renderer)
{
    auto player = em.create_entity();
    player->transform.position.x = SCREEN_WIDTH / 2;
    player->transform.position.y = SCREEN_HEIGHT / 2;

    auto t = rendering::Texture::load_from_bmp("assets/dude.bmp", renderer);
    player->add_component<components::RenderableComponent>(renderer, std::move(t));
    player->add_component<components::PhysicsComponent>();
    player->add_component<components::InputComponent>();
}

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not be initialized! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
        return 1;
    }

    try
    {
        auto w = rendering::Window::create("Elsa!", SCREEN_WIDTH, SCREEN_HEIGHT);
        auto r = rendering::Renderer2D::create(w.get(), false);

        auto em = entities::EntityManager();
        setup_entities(em, r.get());
        em.init();

        auto timer = timing::Timer();
        const auto max_dt = 0.032f;
        auto dt = 0.016f;
        auto running = true;
        input::InputManager::register_callback(input::InputEvent::Quit, [&running]()
        {
            running = false;
        });

        timer.start();
        auto num_frames = 0;

        while (running)
        {
            input::InputManager::handle_input();

            r->set_draw_color(rendering::Color::create(0, 0, 0));
            r->clear();

            em.frame(dt);
            r->present();

            dt = (timer.get_ticks_since_last_call() / 1000.f);
            if (dt > max_dt)
            {
                dt = max_dt;
            }

            if (num_frames % 10 == 0)
            {
                std::cout << "dt: " << dt << std::endl;
            }

            num_frames++;
        }
    }
    catch (const errors::ElsaException& ex)
    {
        std::cout << "Error:" << std::endl << ex.what() << std::endl;
    }

    SDL_Quit();

    return 0;
}