#pragma once

#include <string>
#include <vector>

#include "../typedef.h"

namespace elsa {
    namespace tiles {

        struct TileLayer
        {
            std::vector<i32> data;
            i32 height;
            std::string name;
            i32 opacity;
            std::string type;
            bool visible;
            i32 width;
            i32 x;
            i32 y;
        };

        struct TileProperty
        {
            i32 tile_id;
            bool collidable;
        };

        struct TileSet
        {
            i32 columns;
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
        };

        struct TileMap
        {
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
        };
    }
}