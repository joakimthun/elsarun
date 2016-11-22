#include "vector2D.h"

#include <math.h>

#include "util.h"

namespace elsa {
    namespace math {

        Vector2D::Vector2D() : x(0), y(0) {}

        Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

        Vector2D Vector2D::operator+=(const Vector2D& v2)
        {
            x += v2.x;
            y += v2.y;

            return *this;
        }

        Vector2D Vector2D::operator-(const Vector2D& v2) const
        {
            return Vector2D(x - v2.x, y - v2.y);
        }

        Vector2D Vector2D::operator-=(const Vector2D& v2)
        {
            x -= v2.x;
            y -= v2.y;

            return *this;
        }

        Vector2D Vector2D::operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;

            return *this;
        }

        Vector2D Vector2D::operator*(float scalar)
        {
            return Vector2D(x * scalar, y * scalar);
        }

        Vector2D Vector2D::operator/=(float scalar)
        {
            x /= scalar;
            y /= scalar;

            return *this;
        }

        float Vector2D::length() const
        {
            return static_cast<float>(sqrt(x * x + y * y));
        }

        void Vector2D::normalize()
        {
            float aux_length = length();
            if (aux_length > 0)
            {
                (*this) *= 1 / aux_length;
            }
        }

        void Vector2D::lerp(const Vector2D& goal, float dt)
        {
            x = util::lerp(goal.x, x, dt);
            y = util::lerp(goal.y, y, dt);
        }
    }
}
