#pragma once

#include <cmath>
#include <iostream>
#include <string>

namespace Math
{
    template<typename T = float>
    class Vector2
    {
    public:
        union
        {
            T data[2];
            struct
            {
                T x;
                T y;
            };
        };

        Vector2(const T p_x = 0, const T p_y = 0)
            : x(p_x)
            , y(p_y)
        {}

        Vector2(const Vector2& p_copy)
            : x(p_copy.x)
            , y(p_copy.y)
        {}

        const T DotProduct(const Vector2& p_vector2) const
        {
            return x * p_vector2.x + y * p_vector2.y;
        }

        const T Magnitude() const
        {
            return sqrt(x * x + y * y);
        }

        const T CrossProduct(const Vector2& p_vector2) const
        {
            return x * p_vector2.y - y * p_vector2.x;
        }

        const Vector2& Normalize()
        {
            T magnitude = Magnitude();
            x *= (1 / magnitude);
            y *= (1 / magnitude);
            return *this;
        }

        void Display() const
        {
            std::cout << "[ " << x << ", " << y << " ]" << std::endl;
        }

        const std::string ToString() const
        {
            return "[ " + std::to_string(x) + ", " + std::to_string(y) + " ]";
        }

        friend const Vector2 operator+(const Vector2& p_left, const Vector2& p_right)
        {
            return { p_left.x + p_right.x, p_left.y + p_right.y };
        }

        friend const Vector2 operator-(const Vector2& p_left, const Vector2& p_right)
        {
            return { p_left.x - p_right.x, p_left.y - p_right.y };
        }

        friend const Vector2 operator*(const Vector2& p_left, const T p_multiplier)
        {
            return { p_left.x * p_multiplier, p_left.y * p_multiplier };
        }

        friend const Vector2 operator/(const Vector2& p_left, const T p_divider)
        {
            return { p_left.x / p_divider, p_left.y / p_divider };
        }

        friend Vector2& operator+=(Vector2& p_left, const Vector2& p_right)
        {
            p_left = p_left + p_right;
            return p_left;
        }

        friend Vector2& operator-=(Vector2& p_left, const Vector2& p_right)
        {
            p_left = p_left - p_right;
            return p_left;
        }

        friend Vector2& operator*=(Vector2& p_left, const T p_multiplier)
        {
            p_left = p_left * p_multiplier;
            return p_left;
        }

        friend Vector2& operator/=(Vector2& p_left, const T p_divider)
        {
            p_left = p_left / p_divider;
            return p_left;
        }

        friend bool operator==(const Vector2& p_left, const Vector2& p_right)
        {
            if (p_left.x <= p_right.x + 0.001 && p_left.x >= p_right.x - 0.001 && 
                p_left.y <= p_right.y + 0.001 && p_left.y >= p_right.y - 0.001)
                return true;
            else
                return false;
        }

        friend bool operator!=(const Vector2& p_left, const Vector2& p_right)
        {
            if (p_left.x <= p_right.x + 0.001f && p_left.x >= p_right.x - 0.001f && 
                p_left.y <= p_right.y + 0.001f && p_left.y >= p_right.y - 0.001f)
                return false;
            else
                return true;
        }

        friend bool operator<(const Vector2& p_left, const Vector2& p_right)
        {
            if (p_left.x < p_right.x && p_left.y < p_right.y)
                return true;
            else
                return false;
        }

        friend bool operator<=(const Vector2& p_left, const Vector2& p_right)
        {
            if (p_left.x <= p_right.x && p_left.y <= p_right.y)
                return true;
            else
                return false;
        }

        friend bool operator>(const Vector2& p_left, const Vector2& p_right)
        {
            if (p_left.x > p_right.x && p_left.y > p_right.y)
                return true;
            else
                return false;
        }

        friend bool operator>=(const Vector2& p_left, const Vector2& p_right)
        {
            if (p_left.x >= p_right.x && p_left.y >= p_right.y)
                return true;
            else
                return false;
        }
    };
}