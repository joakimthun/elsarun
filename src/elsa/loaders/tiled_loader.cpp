#include "tiled_loader.h"

#include <json.hpp>
#include <fstream>

#include "../errors/elsa_exception.h"

namespace elsa {
    namespace loaders {

        using json = nlohmann::json;

        void TiledLoader::load_from_json(const std::string& path)
        {
            std::ifstream fs;
            fs.open(path, std::ifstream::in);

            if (!fs.is_open())
            {
                throw errors::ElsaException("TiledLoader::load_from_json: Could not open the file: " + path);
            }

            auto const parsed = json::parse(fs);
        }

    }
}
