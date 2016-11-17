#include <SDL.h>
#include <iostream>

#include "errors/elsa_exception.h"
#include "rendering/window.h"
#include "rendering/renderer2d.h"
#include "rendering/texture.h"
#include "rendering/color.h"
#include "timing/timer.h"

#include "input/input_manager.h"
#include "loaders/tiled_loader.h"

#include "entities/entity.h"
#include "entities/entity_manager.h"

#include "components/input_component.h"
#include "components/renderable_component.h"
#include "components/renderable_rect_component.h"
#include "components/physics_component.h"
#include "components/elsa_ai_component.h"
#include "components/leash_component.h"

using namespace elsa;

auto const SCREEN_WIDTH = 720;
auto const SCREEN_HEIGHT = 1080;

void setup_entities(entities::EntityManager& em, rendering::Renderer2D* renderer)
{
    // Player
    auto player = em.create_entity();
    player->transform.position.x = SCREEN_WIDTH / 2;
    player->transform.position.y = SCREEN_HEIGHT / 2 + 200;

    player->add_component<components::RenderableRectComponent>(renderer, rendering::Color::create(255, 0, 0), 50, 50);
    player->add_component<components::PhysicsComponent>();
    player->add_component<components::InputComponent>();

    // Elsa
    auto elsa = em.create_entity();
    elsa->transform.position.x = SCREEN_WIDTH / 2;
    elsa->transform.position.y = SCREEN_HEIGHT / 2 - 200;

    elsa->add_component<components::RenderableRectComponent>(renderer, rendering::Color::create(0, 255, 0), 50, 50);
    elsa->add_component<components::PhysicsComponent>();
    elsa->add_component<components::ElsaAiComponent>(SCREEN_WIDTH - 100, 100, SCREEN_HEIGHT, 0);
    elsa->add_component<components::LeashComponent>(renderer, player, rendering::Color::create(0, 0, 255));
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
        loaders::TiledLoader::load_from_json("assets/tilesets/background.json");

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

            if (num_frames % 10000 == 0)
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