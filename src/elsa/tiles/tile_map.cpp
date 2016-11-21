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

        TileCoordinates TileMap::get_tile_coordinates(std::size_t column, std::size_t row, u32 tile_width, u32 tile_height)
        {
            return TileCoordinates{ column * tile_width, row * tile_height };
        }

        void TileMap::render_layer(rendering::Renderer2D* renderer, std::size_t layer_index) const
        {
            const auto& tile_layer = layers[layer_index];
            const auto& tile_set = tile_sets[0];
            auto tile_height = tile_set.tile_height;
            auto tile_width = tile_set.tile_width;

            for (std::size_t column = 0; column < tile_layer.width; column++)
            {
                for (std::size_t row = 0; row < tile_layer.height; row++)
                {
                    auto tile = tile_layer.tiles[row][column];
                    if (tile.has_tile)
                    {
                        auto dest_coordinates = get_tile_coordinates(column, row, tile_set.tile_width, tile_set.tile_height);
                        renderer->render_tile(tile_set.texture.get(), dest_coordinates.x, dest_coordinates.y, tile.x, tile.y, tile_width, tile_height);
                    }
                }
            }
        }
    }
}
