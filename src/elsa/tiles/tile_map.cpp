#include "tile_map.h"

#include <cmath>

#include "../rendering/renderer2d.h"

namespace elsa {
    namespace tiles {

        void TileMap::render(rendering::Renderer2D* renderer) const
        {
            for (std::size_t layer_index{ 0 }; layer_index < layers.size(); layer_index++)
            {
                render_layer(renderer, layer_index);
            }
        }

        TileCoordinates TileMap::get_tile_coordinates(std::size_t column, std::size_t row) const
        {
            return TileCoordinates{ column * tile_width, row * tile_height };
        }

        void TileMap::render_layer(rendering::Renderer2D* renderer, std::size_t layer_index) const
        {
            const auto& tile_layer = layers[layer_index];
            const auto& tile_set = tile_sets[0];
            const auto& set_texture = tile_set.texture;
            auto tile_height = tile_set.tile_height;
            auto tile_width = tile_set.tile_width;
            auto map_height = width * tile_width;
            auto map_width = height * tile_height;

            for (std::size_t column = 0; column < tile_layer.width; column++)
            {
                for (std::size_t row = 0; row < tile_layer.height; row++)
                {
                    auto tile_index = tile_layer.data[row][column];
                    if (tile_index != 0)
                    {
                        tile_index = tile_index - 1;
                        auto src_column = tile_index % tile_set.columns;
                        auto src_row = static_cast<std::size_t>(std::floor(tile_index / tile_set.columns));
                        auto tile_dest_coordinates = get_tile_coordinates(column, row);
                        auto tile_src_coordinates = get_tile_coordinates(src_column, src_row);

                        renderer->render_tile(tile_set.texture.get(), tile_dest_coordinates.x, tile_dest_coordinates.y, tile_src_coordinates.x, tile_src_coordinates.y, 64, 64);
                    }
                }
            }
        }
    }
}
