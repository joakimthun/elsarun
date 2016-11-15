#include <SDL.h>
#include <iostream>

#include "errors/elsa_exception.h"
#include "rendering/window.h"
#include "rendering/renderer2d.h"
#include "rendering/texture.h"
#include "rendering/color.h"

#include "entities/entity.h"
#include "entities/entity_manager.h"
#include "components/input_component.h"
#include "components/renderable_component.h"

using namespace elsa;

void setup_entities(entities::EntityManager& em, rendering::Renderer2D* renderer)
{
    auto player = em.create_entity();

    auto t = rendering::Texture::load_from_bmp("assets/dude.bmp", renderer);
    player->add_component<components::RenderableComponent>(renderer, std::move(t));

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
        auto w = rendering::Window::create("Elsa!", 800, 600);
        auto r = rendering::Renderer2D::create(w.get());

        auto em = entities::EntityManager();
        setup_entities(em, r.get());


        auto running = true;
        SDL_Event e;

        while (running)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }

            r->clear();

            em.update(0.016f);
            em.render();

            r->present();
        }
    }
    catch (const errors::ElsaException& ex)
    {
        std::cout << "Error:" << std::endl << ex.what() << std::endl;
    }

    SDL_Quit();

    return 0;
}