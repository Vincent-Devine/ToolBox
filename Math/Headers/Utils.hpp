#pragma once

#include <cmath>
#include <corecrt_math_defines.h>

namespace Math
{
	const float RAD2DEG = 180.f / (float)M_PI;
	const float DEG2RAD = (float)M_PI / 180.f;

	template<typename T = float>
	T Max(const T& a, const T& b);

	template<typename T = float>
	T Min(const T& a, const T& b);

	template <typename T>
	T Abs(const T& a);

	template <typename T>
	T Lerp(const float t, const T& a, const T& b);

	template <typename T>
	T Clamp(const T value, const T min, const T max);
}

#include "../Inlines/Utils.inl"