#pragma once

namespace elsa {
    namespace math {
        namespace util {

            inline float lerp(float goal, float current, float dt)
            {
                auto diff = goal - current;

                if (diff > dt)
                    return current + dt;
                if (diff < -dt)
                    return current - dt;

                return goal;
            }

        }
    }
}