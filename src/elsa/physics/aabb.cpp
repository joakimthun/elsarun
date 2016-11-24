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

        bool AABB::intersects(const AABB& other) const
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

            if (bmax < amax)
            {
                amax = bmax;
            }

            if (amax <= amin)
            {
                return false;
            }

            // Vertical intersection
            amin = y;
            amax = amin + height;
            bmin = other.y;
            bmax = bmin + other.height;

            if (bmin > amin)
            {
                amin = bmin;
            }

            if (bmax < amax)
            {
                amax = bmax;
            }

            if (amax <= amin)
            {
                return false;
            }

            return true;
        }

    }
}
