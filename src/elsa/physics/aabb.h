#pragma once

#include "../typedef.h"

namespace elsa {
    namespace physics {

        struct AABB
        {
            AABB(u32 x, u32 y, u32 width, u32 height);

            bool intersects(const AABB& other) const;

            u32 x;
            u32 y;
            u32 width;
            u32 height;
        };

    }
}
