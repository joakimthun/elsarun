#pragma once

#include <string>
#include <vector>
#include <memory>

#include "../typedef.h"
#include "../rendering/texture.h"
#include "../physics/aabb.h"

namespace elsa {

    namespace rendering {
        Renderer2D;
    }

    namespace tiles {

        struct TileCoordinates
        {
            u32 x;
            u32 y;
        };

        struct Tile
        {
            u32 src_x;
            u32 src_y;
            u32 dest_x;
            u32 dest_y;
            u32 index;
            bool has_tile;
            bool collidable;
        };

        struct TileLayer
        {
            std::vector<std::vector<Tile>> tiles;
            std::vector<physics::AABB> collidable_tiles;
            u32 height;
            std::string name;
            i32 opacity;
            std::string type;
            bool visible;
            u32 width;
            u32 x;
            u32 y;
        };

        struct TileProperty
        {
            u32 tile_id;
            bool collidable;
        };

        struct TileSet
        {
            u32 columns;
            u32 rows;
            i32 firstgid;
            std::string image;
            u32 image_height;
            u32 image_width;
            i32 margin;
            std::string name;
            i32 spacing;
            u32 tile_count;
            u32 tile_height;
            u32 tile_width;
            std::vector<TileProperty> tile_properties;
            std::unique_ptr<rendering::Texture> texture;
        };

        class TileMap
        {
        public:
            void init();
            void render(rendering::Renderer2D* renderer) const;
            static TileCoordinates get_tile_coordinates(std::size_t column, std::size_t row, u32 tile_width, u32 tile_height);

            u32 height;
            std::vector<TileLayer> layers;
            i32 next_object_id;
            std::string orientation;
            std::string render_order;
            u32 tile_height;
            std::vector<TileSet> tile_sets;
            u32 tile_width;
            i32 version;
            u32 width;
        private:
            void render_layer(rendering::Renderer2D* renderer, std::size_t layer_index) const;
            void init_layer(std::size_t layer_index);
        };
    }
}