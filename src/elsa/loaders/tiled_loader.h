#pragma once

#include <json.hpp>
#include <string>
#include <memory>

#include "../tiles/tile_map.h"

namespace elsa {
    namespace loaders {

        using json = nlohmann::json;

        class TiledLoader
        {
        public:
            static std::unique_ptr<const tiles::TileMap> load_from_json(const std::string& path);

        private:
            TiledLoader() = delete;
            static std::unique_ptr<const tiles::TileMap> create_map(const json& map);
        };
    }
}