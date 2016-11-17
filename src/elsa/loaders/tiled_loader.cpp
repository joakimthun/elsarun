#include "tiled_loader.h"

#include <json.hpp>

namespace elsa {
    namespace loaders {

        using json = nlohmann::json;

        void TiledLoader::load_from_json(const std::string& path)
        {
            // create object from string literal
            json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
        }

    }
}
