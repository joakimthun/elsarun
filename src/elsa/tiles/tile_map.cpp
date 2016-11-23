#include "tile_map.h"

#include <cmath>

#include "../rendering/renderer2d.h"

namespace elsa {
    namespace tiles {

        void TileMap::init()
        {
            for (std::size_t layer_index{ 0 }; layer_index < layers.size(); layer_index++)
            {
                init_layer(layer_index);
            }
        }

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

            for (std::size_t column = 0; column < tile_layer.width; column++)
            {
                for (std::size_t row = 0; row < tile_layer.height; row++)
                {
                    const auto& tile = tile_layer.tiles[row][column];
                    if (tile.has_tile)
                    {
                        renderer->render_texture(tile_set.texture.get(), tile.dest_x, tile.dest_y, tile.src_x, tile.src_y, tile_width, tile_height);
                    }
                }
            }
        }

        void TileMap::init_layer(std::size_t layer_index)
        {
            // Init dest coordinates and collidable_tiles

            auto& tile_layer = layers[layer_index];
            const auto& tile_set = tile_sets[0];

            for (std::size_t column = 0; column < tile_layer.width; column++)
            {
                for (std::size_t row = 0; row < tile_layer.height; row++)
                {
                    auto& tile = tile_layer.tiles[row][column];
                    if (tile.has_tile)
                    {
                        auto dest_coordinates = get_tile_coordinates(column, row, tile_set.tile_width, tile_set.tile_height);
                        tile.dest_x = dest_coordinates.x;
                        tile.dest_y = dest_coordinates.y;

                        if (tile.collidable)
                        {
                            tile_layer.collidable_tiles.push_back(physics::AABB(tile.dest_x, tile.dest_y, tile_set.tile_width, tile_set.tile_height));
                        }
                    }
                }
            }
        }
    }
}
