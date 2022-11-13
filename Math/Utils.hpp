#pragma once

#include <cmath>
#include <corecrt_math_defines.h>

namespace Math
{
	const float RAD2DEG = 180.f / M_PI;
	const float DEG2RAD = M_PI / 180.f;

	template<typename T = float>
	T Max(const T& a, const T& b)
	{
		if (a > b) return a;
		else return b;

	}
	template<typename T = float>
	T Min(const T& a, const T& b)
	{
		if (a < b) return a;
		else return b;
	}

	template <typename T>
	T Abs(const T& a)
	{
		return a < 0 ? -a : a;
	}

	template <typename T>
	T Lerp(const float t, const T& a, const T& b)
	{
		return t * a + (1 - t) * b;
	}

	template <typename T>
	T Clamp(const T value, const T min, const T max)
	{
		if (value < min)
			return min;
		if (value > max)
			return max;
		return value;
	}
}