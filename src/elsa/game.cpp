#include "game.h"

#include <iostream>

#include "errors/elsa_exception.h"
#include "rendering/texture.h"
#include "rendering/color.h"
#include "math/vector2D.h"
#include "input/input_manager.h"
#include "loaders/tiled_loader.h"
#include "sprites/sprite.h"

#include "entities/entity.h"

#include "components/input_component.h"
#include "components/renderable_component.h"
#include "components/renderable_rect_component.h"
#include "components/physics_component.h"
#include "components/elsa_ai_component.h"
#include "components/leash_component.h"

auto const SCREEN_WIDTH = 1080;
auto const SCREEN_HEIGHT = 720;
auto const GRAVITY = elsa::math::Vector2D(0, 700.f);

namespace elsa {

    Game::Game() {}

    Game::~Game() {}

    void Game::init()
    {
        try
        {
            window_ = rendering::Window::create("Elsa!", SCREEN_WIDTH, SCREEN_HEIGHT);
            renderer_ = rendering::Renderer2D::create(window_.get(), false);

            //tile_map_ = loaders::TiledLoader::load_from_json("assets/tilesets/background.json", renderer_.get());
            tile_map_ = loaders::TiledLoader::load_from_json("assets/tilesets/platformer_bg.json", renderer_.get());

            entity_manager_ = std::make_unique<entities::EntityManager>(tile_map_.get());
            setup_entities();
            entity_manager_->init();

            timer_ = std::make_unique<timing::Timer>();
        }
        catch (const errors::ElsaException& ex)
        {
            std::cout << "Error:" << std::endl << ex.what() << std::endl;
        }
    }

    void Game::run()
    {
        const auto max_dt = 0.032f;
        auto dt = 0.016f;
        auto running = true;

        input::InputManager::register_callback(input::InputEvent::Quit, [&running]()
        {
            std::cout << "input::InputEvent::Quit" << std::endl;
            running = false;
        });

        timer_->start();
        auto num_frames = 0;

        // Test sprite
        //auto test_sprite_texture = rendering::Texture::load_from_file("assets/sprites/alien_beige.png", renderer_.get());
        //auto test_sprite = sprites::Sprite(std::move(test_sprite_texture), 0.25f);
        //test_sprite.add_frame(0, 294, 68, 93);
        //test_sprite.add_frame(0, 100, 70, 96);

        auto test_sprite_texture = rendering::Texture::load_from_file("assets/sprites/dog.png", renderer_.get());
        auto test_sprite = sprites::Sprite(std::move(test_sprite_texture), 0.016f);

        auto s_height = 129;
        test_sprite.add_frame(0, 0, 245, s_height);
        test_sprite.add_frame(0, s_height * 1, 245, s_height);
        test_sprite.add_frame(0, s_height * 2, 245, s_height);
        test_sprite.add_frame(0, s_height * 3, 245, s_height);
        test_sprite.add_frame(0, s_height * 4, 245, s_height);
        test_sprite.add_frame(0, s_height * 5, 245, s_height);
        test_sprite.add_frame(0, s_height * 6, 245, s_height);
        test_sprite.add_frame(0, s_height * 7, 245, s_height);
        test_sprite.add_frame(0, s_height * 8, 245, s_height);
        test_sprite.add_frame(0, s_height * 9, 245, s_height);
        test_sprite.add_frame(0, s_height * 10, 245, s_height);
        test_sprite.add_frame(0, s_height * 11, 245, s_height);
        test_sprite.add_frame(0, s_height * 12, 245, s_height);
        test_sprite.add_frame(0, s_height * 13, 245, s_height);
        test_sprite.add_frame(0, s_height * 14, 245, s_height);
        test_sprite.add_frame(0, s_height * 15, 245, s_height);
        test_sprite.add_frame(0, s_height * 16, 245, s_height);
        test_sprite.add_frame(0, s_height * 17, 245, s_height);

        while (running)
        {
            input::InputManager::handle_input();

            renderer_->set_draw_color(rendering::Color::create(0, 0, 0));
            renderer_->clear();

            // Test

            tile_map_->render(renderer_.get(), true);
            test_sprite.update(dt);
            test_sprite.render(renderer_.get(), 50, 50);

            // Test

            entity_manager_->frame(dt);

            renderer_->present();

            dt = (timer_->get_ticks_since_last_call() / 1000.f);
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

    void Game::setup_entities()
    {
        // Player
        auto player = entity_manager_->create_entity();
        player->transform.position.x = SCREEN_WIDTH / 2;
        player->transform.position.y = SCREEN_HEIGHT / 2;

        player->add_component<components::PhysicsComponent>(GRAVITY, 50, 50);
        player->add_component<components::RenderableRectComponent>(renderer_.get(), rendering::Color::create(0, 0, 255), 50, 50, true);
        player->add_component<components::InputComponent>();

        // Elsa
        //auto elsa = em.create_entity();
        //elsa->transform.position.x = SCREEN_WIDTH / 2;
        //elsa->transform.position.y = SCREEN_HEIGHT / 2 - 200;
        //
        //elsa->add_component<components::RenderableRectComponent>(renderer, rendering::Color::create(0, 255, 0), 50, 50);
        //elsa->add_component<components::PhysicsComponent>(math::Vector2D(0, 0));
        //elsa->add_component<components::ElsaAiComponent>(SCREEN_WIDTH - 100, 100, SCREEN_HEIGHT, 0);
        //elsa->add_component<components::LeashComponent>(renderer, player, rendering::Color::create(0, 0, 255));
    }
}
