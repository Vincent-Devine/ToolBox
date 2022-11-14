#include "../Header/UnitTestVector2.hpp"

#include "../../Math/Vector2.hpp"
#include "../Libs/glm/vec2.hpp"
#include "../Libs/glm/geometric.hpp"

namespace UnitTest
{
	const bool TestUnitOperatorVector2()
	{
		// Operator +
		if ((Math::Vector2(1.f, 1.f) + Math::Vector2(1.f, 1.f)) != Math::Vector2(2.f, 2.f))
		{
			std::cout << "Fail on Math::Vector2 Operator + " << std::endl;
			return false;
		}

		// Operator -
		if ((Math::Vector2(1.f, 1.f) - Math::Vector2(1.f, 1.f)) != Math::Vector2(0.f, 0.f))
		{
			std::cout << "Fail on Math::Vector2 Operator - " << std::endl;
			return false;
		}

		// Operator *
		if ((Math::Vector2(1.f, 1.f) * 2.f) != Math::Vector2(2.f, 2.f))
		{
			std::cout << "Fail on Math::Vector2 Operator * " << std::endl;
			return false;
		}

		// Operator /
		if ((Math::Vector2(2.f, 2.f) / 2.f) != Math::Vector2(1.f, 1.f))
		{
			std::cout << "Fail on Math::Vector2 Operator / " << std::endl;
			return false;
		}

		// Operator +=
		Math::Vector2 vector2 = Math::Vector2(1.f, 1.f);
		vector2 += Math::Vector2(1.f, 1.f);
		if (vector2 != Math::Vector2(2.f, 2.f))
		{
			std::cout << "Fail on Math::Vector2 Operator += " << std::endl;
			return false;
		}

		// Operator -=
		vector2 = Math::Vector2(1.f, 1.f);
		vector2 -= Math::Vector2(1.f, 1.f);
		if (vector2 != Math::Vector2(0.f, 0.f))
		{
			std::cout << "Fail on Math::Vector2 Operator -= " << std::endl;
			return false;
		}

		// Operator *=
		vector2 = Math::Vector2(1.f, 1.f);
		vector2 *= 2.f;
		if (vector2 != Math::Vector2(2.f, 2.f))
		{
			std::cout << "Fail on Math::Vector2 Operator *= " << std::endl;
			return false;
		}

		// Operator /=
		vector2 = Math::Vector2(2.f, 2.f);
		vector2 /= 2.f;
		if (vector2 != Math::Vector2(1.f, 1.f))
		{
			std::cout << "Fail on Math::Vector2 Operator /= " << std::endl;
			return false;
		}

		return true;
	}

	const bool TestUnitDotProductVector2()
	{
		Math::Vector2 v1(1.f, 4.f);
		Math::Vector2 v2(2.f, 3.f);
		glm::vec2 v3(1.f, 4.f);
		glm::vec2 v4(2.f, 3.f);

		const float myResult = Math::Vector2::DotProduct(v1, v2);
		const float resultWanted = glm::dot(v3, v4);

		if (myResult != resultWanted)
		{
			std::cout << "Fail on Math::Vector2::DotProduct" << std::endl;
			return false;
		}

		return true;
	}

	const bool TestUnitMagnitudeVector2()
	{
		Math::Vector2 v1(1.f, 4.f);
		glm::vec2 v2(1.f, 4.f);

		const float myResult = Math::Vector2::Magnitude(v1);
		const float resultWanted = glm::length(v2);

		if (myResult != resultWanted)
		{
			std::cout << "Fail on Math::Vector2::Magnitude" << std::endl;
			return false;
		}

		return true;
	}

	const bool TestUnitNormalizeVector2()
	{
		Math::Vector2 v1(1.f, 4.f);
		glm::vec2 v2(1.f, 4.f);

		const Math::Vector2 myResult = Math::Vector2::Normalize(v1);
		const glm::vec2 resultWanted = glm::normalize(v2);

		if (myResult.x != resultWanted.x && myResult.y != resultWanted.y)
		{
			std::cout << "Fail on Math::Vector2::Normalize" << std::endl;
			return false;
		}

		return true;
	}
	
	const bool TestVector2()
	{
		if(TestUnitOperatorVector2() &&
			TestUnitDotProductVector2() &&
			TestUnitMagnitudeVector2() &&
			TestUnitNormalizeVector2())
		{
			std::cout << "Vector2 : OK" << std::endl;
			return true;
		}
		std::cout << "Vector2 : Fail" << std::endl;
		return false;
	}
}