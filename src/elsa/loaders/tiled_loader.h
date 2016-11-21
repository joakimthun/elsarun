#pragma once

#include <json.hpp>
#include <string>
#include <memory>

#include "../tiles/tile_map.h"

namespace elsa {

    namespace rendering {
        class Renderer2D;
    }

    namespace loaders {

        using json = nlohmann::json;

        class TiledLoader
        {
        public:
            static std::unique_ptr<const tiles::TileMap> load_from_json(const std::string& path, rendering::Renderer2D* renderer);

        private:
            TiledLoader() = delete;
            static std::unique_ptr<const tiles::TileMap> create_map(const json& map, rendering::Renderer2D* renderer);
        };
    }
}