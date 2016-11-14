#include <SDL.h>
#include <iostream>

#include "errors/elsa_exception.h"
#include "rendering/window.h"
#include "rendering/renderer.h"
#include "rendering/texture.h"
#include "rendering/color.h"

#include "entities/entity.h"
#include "entities/entity_manager.h"
#include "components/input_component.h"
#include "components/renderable_component.h"

using namespace elsa;

void setup_entities(entities::EntityManager& em)
{
    auto player = em.create_entity();
    player->add_component<components::RenderableComponent>();
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
        auto em = entities::EntityManager();
        setup_entities(em);

        auto w = rendering::Window::create("Elsa!", 800, 600);
        auto r = rendering::Renderer::create(w.get());
        auto t = rendering::Texture::load_from_bmp("assets/dude.bmp", r.get());

        r->clear();

        r->render_texture(t.get());

        r->set_draw_color(rendering::Color::create(0, 0, 255));
        r->fill_rect(100, 100, 100, 100);

        r->present();

        SDL_Delay(1500);
    }
    catch (const errors::ElsaException& ex)
    {
        std::cout << "Error:" << std::endl << ex.what() << std::endl;
    }

    SDL_Quit();

    return 0;
}