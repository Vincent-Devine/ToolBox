#pragma once

#include <cmath>
#include <string>
#include <iostream>

namespace Math
{
	template<typename T = float>
	class Vector3
	{
	public:
		union
		{
			T data[3];
			struct
			{
				T x;
				T y;
				T z;
			};
			struct
			{
				T r;
				T g;
				T b;
			};
		};

		Vector3(const T p_x = 0, const T p_y = 0, const T p_z = 0)
			: x(p_x)
			, y(p_y)
			, z(p_z)
		{}

		Vector3(const Vector3& p_copy)
			: x(p_copy.x)
			, y(p_copy.y)
			, z(p_copy.z)
		{}

		const T DotProduct(const Vector3& p_vector3) const
		{
			return x * p_vector3.x + y * p_vector3.y + z * p_vector3.z;
		}

		const T Magnitude() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		const Vector3 CrossProduct(const Vector3& p_vector3) const
		{
			return { (y * p_vector3.z) - (z * p_vector3.y), (z * p_vector3.x) - (x * p_vector3.z), (x * p_vector3.y) - (y * p_vector3.x) };
		}

		const Vector3& Normalize()
		{
			T magnitude = Magnitude();
			if (magnitude != 0)
			{
				x *= (1 / magnitude);
				y *= (1 / magnitude);
				z *= (1 / magnitude);
			}
			return *this;
		}

		void Display() const
		{
			std::cout << "[ " << x << ", " << y << ", " << z << " ]" << std::endl;
		}

		const std::string ToString() const
		{
			return "[ " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + " ]";
		}

		friend Vector3<T> operator+(const Vector3& p_left, const Vector3& p_right)
		{
			return { p_left.x + p_right.x, p_left.y + p_right.y, p_left.z + p_right.z };
		}

		friend Vector3<T> operator-(const Vector3& p_left, const Vector3& p_right)
		{
			return { p_left.x - p_right.x, p_left.y - p_right.y, p_left.z - p_right.z };
		}

		friend Vector3<T> operator-(const Vector3 p_right)
		{
			return { -p_right.x, -p_right.y, -p_right.z };
		}

		friend Vector3<T> operator*(const Vector3& p_left, const T multiplier)
		{
			return { p_left.x * multiplier, p_left.y * multiplier, p_left.z * multiplier };
		}

		friend Vector3<T> operator/(const Vector3& p_left, const T divider)
		{
			return { p_left.x / divider, p_left.y / divider, p_left.z / divider };
		}

		friend Vector3<T>& operator+=(Vector3& p_left, const Vector3& p_right)
		{
			p_left = p_left + p_right;
			return p_left;
		}

		friend Vector3<T>& operator-=(Vector3& p_left, const Vector3& p_right)
		{
			p_left = p_left - p_right;
			return p_left;
		}

		friend Vector3<T>& operator*=(Vector3& p_left, const T multipler)
		{
			p_left = p_left * multipler;
			return p_left;
		}

		friend Vector3<T>& operator/=(Vector3& p_left, const T divider)
		{
			p_left = p_left / divider;
			return p_left;
		}

		friend bool operator==(const Vector3& p_left, const Vector3& p_right)
		{
			if (p_left.x <= p_right.x + 0.001f && p_left.x >= p_right.x - 0.001f &&
				p_left.y <= p_right.y + 0.001f && p_left.y >= p_right.y - 0.001f &&
				p_left.z <= p_right.z + 0.001f && p_left.z >= p_right.z - 0.001f)
				return true;
			else
				return false;
		}

		friend bool operator!=(const Vector3& p_left, const Vector3& p_right)
		{
			if (p_left.x <= p_right.x + 0.001f && p_left.x >= p_right.x - 0.001f &&
				p_left.y <= p_right.y + 0.001f && p_left.y >= p_right.y - 0.001f &&
				p_left.z <= p_right.z + 0.001f && p_left.z >= p_right.z - 0.001f)
				return false;
			else
				return true;
		}

		friend bool operator<(const Vector3& p_left, const Vector3& p_right)
		{
			if (p_left.x < p_right.x && p_left.y < p_right.y && p_left.z < p_right.z)
				return true;
			else
				return false;
		}

		friend bool operator<=(const Vector3& p_left, const Vector3& p_right)
		{
			if (p_left.x <= p_right.x && p_left.y <= p_right.y && p_left.z <= p_right.z)
				return true;
			else
				return false;
		}

		friend bool operator>(const Vector3& p_left, const Vector3& p_right)
		{
			if (p_left.x > p_right.x && p_left.y > p_right.y && p_left.z > p_right.z)
				return true;
			else
				return false;
		}

		friend bool operator>=(const Vector3& p_left, const Vector3& p_right)
		{
			if (p_left.x >= p_right.x && p_left.y >= p_right.y && p_left.z >= p_right.z)
				return true;
			else
				return false;
		}
	};
}