#pragma once

#include <string>
#include <vector>
#include <memory>

#include "../typedef.h"
#include "../rendering/texture.h"

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

        struct TileLayer
        {
            std::vector<std::vector<i32>> data;
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
            i32 tile_id;
            bool collidable;
        };

        struct TileSet
        {
            u32 columns;
            u32 rows;
            i32 firstgid;
            std::string image;
            i32 image_height;
            i32 image_width;
            i32 margin;
            std::string name;
            i32 spacing;
            i32 tile_count;
            i32 tile_height;
            i32 tile_width;
            std::vector<TileProperty> tile_properties;
            std::unique_ptr<rendering::Texture> texture;
        };

        class TileMap
        {
        public:
            void render(rendering::Renderer2D* renderer) const;

            i32 height;
            std::vector<TileLayer> layers;
            i32 next_object_id;
            std::string orientation;
            std::string render_order;
            i32 tile_height;
            std::vector<TileSet> tile_sets;
            i32 tile_width;
            i32 version;
            i32 width;
        private:
            TileCoordinates get_tile_coordinates(std::size_t column, std::size_t row) const;
            void render_layer(rendering::Renderer2D* renderer, std::size_t layer_index) const;
        };
    }
}