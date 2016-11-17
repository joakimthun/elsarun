#include "tiled_loader.h"

#include <fstream>

#include "../errors/elsa_exception.h"

namespace elsa {
    namespace loaders {

        std::unique_ptr<const tiles::TileMap> TiledLoader::load_from_json(const std::string& path)
        {
            std::ifstream fs;
            fs.open(path, std::ifstream::in);

            if (!fs.is_open())
            {
                throw errors::ElsaException("TiledLoader::load_from_json: Could not open the file: " + path);
            }

            return create_map(json::parse(fs));
        }

        std::unique_ptr<const tiles::TileMap> TiledLoader::create_map(const json& map)
        {
            auto tile_map = std::make_unique<tiles::TileMap>();

            tile_map->height = map["height"];
            tile_map->next_object_id = map["nextobjectid"];
            tile_map->orientation = map["orientation"];
            tile_map->render_order = map["renderorder"];
            tile_map->tile_height = map["tileheight"];
            tile_map->tile_width = map["tilewidth"];
            tile_map->version = map["version"];
            tile_map->width = map["width"];

            for (const auto& json_layer : map["layers"])
            {
                tile_map->layers.push_back(tiles::TileLayer{});
                auto& layer = tile_map->layers.back();

                for (const auto& json_data : json_layer["data"])
                {
                    layer.data.push_back(json_data);
                }

                layer.height = json_layer["height"];
                layer.name = json_layer["name"];
                layer.opacity = json_layer["opacity"];
                layer.type = json_layer["type"];
                layer.visible = json_layer["visible"];
                layer.width = json_layer["width"];
                layer.x = json_layer["x"];
                layer.y = json_layer["y"];
            }

            for (const auto& json_set : map["tilesets"])
            {
                tile_map->tile_sets.push_back(tiles::TileSet{});
                auto& set = tile_map->tile_sets.back();

                set.columns = json_set["columns"];
                set.firstgid = json_set["firstgid"];
                set.image = json_set["image"];
                set.image_width = json_set["imagewidth"];
                set.margin = json_set["margin"];
                set.name = json_set["name"];
                set.spacing = json_set["spacing"];
                set.tile_count = json_set["tilecount"];
                set.tile_height = json_set["tileheight"];

                auto tile_properties_json = json_set["tileproperties"];
                for (i32 i{ 0 }; i < set.tile_count; i++)
                {
                    auto prop_json = tile_properties_json[std::to_string(i)];
                    if (!prop_json.is_null())
                    {
                        set.tile_properties.push_back(tiles::TileProperty{ i, prop_json["collidable"] });
                    }
                }
            }

            return std::move(tile_map);
        }

    }
}
