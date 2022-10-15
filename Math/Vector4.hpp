#pragma once

#include <cmath>
#include <string>
#include <iostream>

#include "Vector3.hpp"

namespace Math
{
	template<typename T = float>
	class Vector4
	{
	public:
		union
		{
			T data[4];
			struct
			{
				T x;
				T y;
				T z;
				T w;
			};
			struct
			{
				T r;
				T g;
				T b;
				T a;
			};
		};

		Vector4(const T p_x = 0, const T p_y = 0, const T p_z = 0, const T p_w = 0)
			: x(p_x)
			, y(p_y)
			, z(p_z)
			, w(p_w)
		{}

		Vector4(const Vector3<T>& p_vector3, const T p_w)
			: x(p_vector3.x)
			, y(p_vector3.y)
			, z(p_vector3.z)
			, w(p_w)
		{
		}

		Vector4(const Vector4& p_copy)
			: x(p_copy.x)
			, y(p_copy.y)
			, z(p_copy.z)
			, w(p_copy.w)
		{
		}

		const T DotProduct(const Vector4& p_vector4) const
		{
			return x * p_vector4.x + y * p_vector4.y + z * p_vector4.z + w * p_vector4.w;
		}

		const T Magnitude()
		{
			return sqrt(x * x + y * y + z * z + w * w);
		}

		const T CrossProduct(const Vector4& p_vector4) const
		{
			return ((x * p_vector4.x + x * p_vector4.y + x * p_vector4.z + x * p_vector4.w) + (y * p_vector4.x + y * p_vector4.y + y * p_vector4.z + y * p_vector4.w) + (z * p_vector4.x + z * p_vector4.y + z * p_vector4.z + z * p_vector4.w) + (w * p_vector4.x + w * p_vector4.y + w * p_vector4.z + w * p_vector4.w));
		}

		const Vector4& Normalize()
		{
			float magnitude = Magnitude();
			x *= (1 / magnitude);
			y *= (1 / magnitude);
			z *= (1 / magnitude);
			w *= (1 / magnitude);
			return *this;
		}

		void Homogenize()
		{
			if (w != 0)
			{
				x /= w;
				y /= w;
				z /= w;
				w /= w;
			}
		}

		const Vector3<T> ToVector3() const
		{
			return { x, y, z };
		}

		void Display() const
		{
			std::cout << "[ " << x << ", " << y << ", " << z << ", " << w << " ]" << std::endl;
		}

		std::string ToString() const
		{
			return "[ " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + " ]";
		}

		friend Vector4 operator+(const Vector4& p_left, const Vector4& p_right)
		{
			return { p_left.x + p_right.x, p_left.y + p_right.y, p_left.z + p_right.z, p_left.w + p_right.w };
		}

		friend Vector4 operator-(const Vector4& p_left, const Vector4& p_right)
		{
			return { p_left.x - p_right.x, p_left.y - p_right.y, p_left.z - p_right.z, p_left.w - p_right.w };
		}

		friend Vector4 operator*(const Vector4& p_left, const T multiplier)
		{
			return { p_left.x * multiplier, p_left.y * multiplier, p_left.z * multiplier, p_left.w * multiplier };
		}

		friend Vector4 operator/(const Vector4& p_left, const T divider)
		{
			return { p_left.x / divider, p_left.y / divider, p_left.z / divider, p_left.w / divider };
		}

		friend Vector4& operator+=(Vector4& p_left, const Vector4& p_right)
		{
			p_left = p_left + p_right;
			return p_left;
		}

		friend Vector4& operator-=(Vector4& p_left, const Vector4& p_right)
		{
			p_left = p_left - p_right;
			return p_left;
		}

		friend Vector4& operator*=(Vector4& p_left, const T multipler)
		{
			p_left = p_left * multipler;
			return p_left;
		}

		friend Vector4& operator/=(Vector4& p_left, const T divider)
		{
			p_left = p_left / divider;
			return p_left;
		}

		friend bool operator==(const Vector4& p_left, const Vector4& p_right)
		{
			if (p_left.x <= p_right.x + 0.001f && p_left.x >= p_right.x - 0.001f &&
				p_left.y <= p_right.y + 0.001f && p_left.y >= p_right.y - 0.001f &&
				p_left.z <= p_right.z + 0.001f && p_left.z >= p_right.z - 0.001f &&
				p_left.w <= p_right.w + 0.001f && p_left.w >= p_right.w - 0.001f)
				return true;
			else
				return false;
		}

		friend bool operator!=(const Vector4& p_left, const Vector4& p_right)
		{
			if (p_left.x <= p_right.x + 0.001f && p_left.x >= p_right.x - 0.001f &&
				p_left.y <= p_right.y + 0.001f && p_left.y >= p_right.y - 0.001f &&
				p_left.z <= p_right.z + 0.001f && p_left.z >= p_right.z - 0.001f &&
				p_left.w <= p_right.w + 0.001f && p_left.w >= p_right.w - 0.001f)
				return false;
			else
				return true;
		}

		friend bool operator<(const Vector4& p_left, const Vector4& p_right)
		{
			if (p_left.x < p_right.x && p_left.y < p_right.y && p_left.z < p_right.z && p_left.w < p_right.w)
				return true;
			else
				return false;
		}

		friend bool operator<=(const Vector4& p_left, const Vector4& p_right)
		{
			if (p_left.x <= p_right.x && p_left.y <= p_right.y && p_left.z <= p_right.z && p_left.w <= p_right.w)
				return true;
			else
				return false;
		}

		friend bool operator>(const Vector4& p_left, const Vector4& p_right)
		{
			if (p_left.x > p_right.x && p_left.y > p_right.y && p_left.z > p_right.z && p_left.w > p_right.w)
				return true;
			else
				return false;
		}

		friend bool operator>=(const Vector4& p_left, const Vector4& p_right)
		{
			if (p_left.x >= p_right.x && p_left.y >= p_right.y && p_left.z >= p_right.z && p_left.w >= p_right.w)
				return true;
			else
				return false;
		}
	};
}