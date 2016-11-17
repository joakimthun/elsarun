#pragma once

#include <string>

namespace elsa {
    namespace loaders {

        class TiledLoader
        {
        public:
            static void load_from_json(const std::string& path);

        private:
            TiledLoader() = delete;
        };
    }
}