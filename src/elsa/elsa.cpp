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

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not be initialized! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
        return 1;
    }

    try
    {
        auto em = new entities::EntityManager();

        std::cout << "else.cpp get_component_type_id InputComponent:" << entities::get_component_type_id<components::InputComponent>() << std::endl;
        std::cout << "else.cpp get_component_type_id RenderableComponent:" << entities::get_component_type_id<components::RenderableComponent>() << std::endl;
        std::cout << "else.cpp get_component_type_id InputComponent:" << entities::get_component_type_id<components::InputComponent>() << std::endl;
        std::cout << "else.cpp get_component_type_id InputComponent:" << entities::get_component_type_id<components::InputComponent>() << std::endl;

        auto e = new entities::Entity();
        std::cout << "has_component InputComponent:" << (e->has_component<components::InputComponent>() ? "true" : "false") <<  std::endl;

        auto c = e->get_component<components::InputComponent>();

        e->add_component<components::InputComponent>();

        std::cout << "has_component InputComponent:" << (e->has_component<components::InputComponent>() ? "true" : "false") << std::endl;

        c = e->get_component<components::InputComponent>();
        c->update(0.0f);

        std::cout << "has_component RenderableComponent:" << (e->has_component<components::RenderableComponent>() ? "true" : "false") << std::endl;

        e->add_component<components::RenderableComponent>();

        std::cout << "has_component RenderableComponent:" << (e->has_component<components::RenderableComponent>() ? "true" : "false") << std::endl;

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