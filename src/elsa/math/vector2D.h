#pragma once

namespace elsa {
    namespace math {

        struct Vector2D {
            float x;
            float y;

            Vector2D();
            Vector2D(float x, float y);

            Vector2D operator+=(const Vector2D& v2);
            Vector2D operator-(const Vector2D& v2) const;
            Vector2D operator-=(const Vector2D& v2);
            Vector2D operator*=(float scalar);
            Vector2D operator*(float scalar);
            Vector2D operator/=(float scalar);
            float length() const;
            void normalize();
        };
    }
}