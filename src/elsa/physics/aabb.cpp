#include "aabb.h"

namespace elsa {
    namespace physics {

        AABB::AABB(u32 x, u32 y, u32 width, u32 height)
            :
            x(x),
            y(y),
            width(width),
            height(height)
        {
        }

        bool AABB::intersects(const AABB& other)
        {
            return intersects(other, AABB(0, 0, 0, 0));
        }

        bool AABB::intersects(const AABB& other, AABB& result)
        {
            u32 amin, amax, bmin, bmax;

            // Horizontal intersection
            amin = x;
            amax = amin + width;
            bmin = other.x;
            bmax = bmin + other.width;

            if (bmin > amin)
            {
                amin = bmin;
            }

            result.x = amin;
            if (bmax < amax)
            {
                amax = bmax;
            }

            result.width = amax - amin;

            // Vertical intersection
            amin = y;
            amax = amin + height;
            bmin = other.y;
            bmax = bmin + other.height;

            if (bmin > amin)
            {
                amin = bmin;
            }

            result.y = amin;
            if (bmax < amax)
            {
                amax = bmax;
            }

            result.height = amax - amin;

            return !result.is_empty();
        }

        bool AABB::is_empty()
        {
            return ((width <= 0) || (height <= 0));
        }

    }
}
