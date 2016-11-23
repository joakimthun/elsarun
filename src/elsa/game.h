#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <memory>

#include "rendering/window.h"
#include "rendering/renderer2d.h"
#include "timing/timer.h"
#include "entities/entity_manager.h"
#include "tiles/tile_map.h"

namespace elsa {

    class Game
    {
    public:
        Game();
        ~Game();

        void init();
        void run();

    private:
        void setup_entities();

        std::unique_ptr<rendering::Window> window_;
        std::unique_ptr<rendering::Renderer2D> renderer_;
        std::unique_ptr<timing::Timer> timer_;
        std::unique_ptr<entities::EntityManager> entity_manager_;
        std::unique_ptr<const tiles::TileMap> tile_map_;
    };
}
