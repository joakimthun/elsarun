#pragma once

#include "../typedef.h"

namespace elsa {
    namespace physics {

        struct AABB
        {
            AABB(u32 x, u32 y, u32 width, u32 height);

            bool intersects(const AABB& other);
            bool intersects(const AABB& other, AABB& result);
            bool is_empty();

            u32 x;
            u32 y;
            u32 width;
            u32 height;
        };

    }
}
