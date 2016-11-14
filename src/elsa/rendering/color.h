#pragma once

#include "../typedef.h"

namespace elsa {
    namespace rendering {

        struct Color
        {
            u8 r;
            u8 g;
            u8 b;
            u8 a;

            static inline Color create(u8 r, u8 g, u8 b)
            {
                return Color{ r, g, b, 255 };
            }

            static inline Color create(u8 r, u8 g, u8 b, u8 a)
            {
                return Color{r, g, b, a};
            }
        };

    }
}
