#include "../Header/UnitTestVector2.hpp"

#include "../../Math/Vector2.hpp"
#include "../Libs/glm/vec2.hpp"
#include "../Libs/glm/geometric.hpp"

namespace UnitTest
{
	const bool TestUnitOperator()
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
		Math::Vector2 vector2 = Math::Vector2<float>(1.f, 1.f);
		vector2 += Math::Vector2(1.f, 1.f);
		if (vector2 != Math::Vector2(2.f, 2.f))
		{
			std::cout << "Fail on Math::Vector2 Operator += " << std::endl;
			return false;
		}

		// Operator -=
		vector2 = Math::Vector2<float>(1.f, 1.f);
		vector2 -= Math::Vector2(1.f, 1.f);
		if (vector2 != Math::Vector2(0.f, 0.f))
		{
			std::cout << "Fail on Math::Vector2 Operator -= " << std::endl;
			return false;
		}

		// Operator *=
		vector2 = Math::Vector2<float>(1.f, 1.f);
		vector2 *= 2.f;
		if (vector2 != Math::Vector2(2.f, 2.f))
		{
			std::cout << "Fail on Math::Vector2 Operator *= " << std::endl;
			return false;
		}

		// Operator /=
		vector2 = Math::Vector2<float>(2.f, 2.f);
		vector2 /= 2.f;
		if (vector2 != Math::Vector2(1.f, 1.f))
		{
			std::cout << "Fail on Math::Vector2 Operator /= " << std::endl;
			return false;
		}

		return true;
	}

	const bool TestUnitDotProduct()
	{
		Math::Vector2<float> v1(1.f, 4.f);
		Math::Vector2<float> v2(2.f, 3.f);
		glm::vec2 v3(1.f, 4.f);
		glm::vec2 v4(2.f, 3.f);

		const float myResult = v1.DotProduct(v2);
		const float resultWanted = glm::dot(v3, v4);

		if (myResult != resultWanted)
		{
			std::cout << "Fail on Math::Vector2::DotProduct" << std::endl;
			return false;
		}

		return true;
	}

	const bool TestUnitMagnitude()
	{
		Math::Vector2<float> v1(1.f, 4.f);
		glm::vec2 v2(1.f, 4.f);

		const float myResult = v1.Magnitude();
		const float resultWanted = glm::length(v2);

		if (myResult != resultWanted)
		{
			std::cout << "Fail on Math::Vector2::Magnitude" << std::endl;
			return false;
		}

		return true;
	}

	const bool TestUnitCrossProduct()
	{
		Math::Vector2<float> v1(5.f, 4.f);
		Math::Vector2<float> v2(2.f, 3.f);

		const float myResult = v1.CrossProduct(v2);
		const float resultWanted = 7.f;

		if (myResult != resultWanted)
		{
			std::cout << "Fail on Math::Vector2::CrossProduct" << std::endl;
			return false;
		}

		return true;
	}

	const bool TestUnitNormalize()
	{
		Math::Vector2<float> v1(1.f, 4.f);
		glm::vec2 v2(1.f, 4.f);

		const Math::Vector2 myResult = v1.Normalize();
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
		if(TestUnitOperator() &&
			TestUnitDotProduct() && 
			TestUnitMagnitude() && 
			TestUnitCrossProduct() &&
			TestUnitNormalize())
			return true;
		return false;
	}
}