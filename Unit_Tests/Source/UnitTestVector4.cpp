#include "../Header/UnitTestVector4.hpp"

#include "../../Math/Vector4.hpp"
#include "../Libs/glm/vec4.hpp"
#include "../Libs/glm/geometric.hpp"

namespace UnitTest
{
    const bool TestUnitOperatorVector4()
    {
        // Operator +
        if ((Math::Vector4(1.f, 1.f, 1.f, 1.f) + Math::Vector4(1.f, 1.f, 1.f, 1.f)) != Math::Vector4(2.f, 2.f, 2.f, 2.f))
        {
            std::cout << "Fail on Math::Vector4 Operator + " << std::endl;
            return false;
        }

        // Operator -
        if ((Math::Vector4(1.f, 1.f, 1.f, 1.f) - Math::Vector4(1.f, 1.f, 1.f, 1.f)) != Math::Vector4(0.f, 0.f, 0.f, 0.f))
        {
            std::cout << "Fail on Math::Vector4 Operator - " << std::endl;
            return false;
        }

        // Operator *
        if ((Math::Vector4(1.f, 1.f, 1.f, 1.f) * 2.f) != Math::Vector4(2.f, 2.f, 2.f, 2.f))
        {
            std::cout << "Fail on Math::Vector4 Operator * " << std::endl;
            return false;
        }

        // Operator /
        if ((Math::Vector4(2.f, 2.f, 2.f, 2.f) / 2.f) != Math::Vector4(1.f, 1.f, 1.f, 1.f))
        {
            std::cout << "Fail on Math::Vector4 Operator / " << std::endl;
            return false;
        }

        // Operator +=
        Math::Vector4 vector4 = Math::Vector4<float>(1.f, 1.f, 1.f, 1.f);
        vector4 += Math::Vector4(1.f, 1.f, 1.f, 1.f);
        if (vector4 != Math::Vector4(2.f, 2.f, 2.f, 2.f))
        {
            std::cout << "Fail on Math::Vector4 Operator += " << std::endl;
            return false;
        }

        // Operator -=
        vector4 = Math::Vector4<float>(1.f, 1.f, 1.f, 1.f);
        vector4 -= Math::Vector4(1.f, 1.f, 1.f, 1.f);
        if (vector4 != Math::Vector4(0.f, 0.f, 0.f, 0.f))
        {
            std::cout << "Fail on Math::Vector4 Operator -= " << std::endl;
            return false;
        }

        // Operator *=
        vector4 = Math::Vector4<float>(1.f, 1.f, 1.f, 1.f);
        vector4 *= 2.f;
        if (vector4 != Math::Vector4(2.f, 2.f, 2.f, 2.f))
        {
            std::cout << "Fail on Math::Vector4 Operator *= " << std::endl;
            return false;
        }

        // Operator /=
        vector4 = Math::Vector4<float>(2.f, 2.f, 2.f, 2.f);
        vector4 /= 2.f;
        if (vector4 != Math::Vector4(1.f, 1.f, 1.f, 1.f))
        {
            std::cout << "Fail on Math::Vector4 Operator /= " << std::endl;
            return false;
        }

        return true;
    }

    const bool TestUnitDotProductVector4()
    {
        Math::Vector4<float> v1(1.f, 4.f, 8.f, 1.f);
        Math::Vector4<float> v2(2.f, 3.f, 7.f, 1.f);
        glm::vec4 v3(1.f, 4.f, 8.f, 1.f);
        glm::vec4 v4(2.f, 3.f, 7.f, 1.f);

        const float myResult = v1.DotProduct(v2);
        const float resultWanted = glm::dot(v3, v4);

        if (myResult != resultWanted)
        {
            std::cout << "Fail on Math::Vector4::DotProduct" << std::endl;
            return false;
        }

        return true;
    }

    const bool TestUnitMagnitudeVector4()
    {
        Math::Vector4<float> v1(1.f, 4.f, 8.f, 1.f);
        glm::vec4 v2(1.f, 4.f, 8.f, 1.f);

        const float myResult = v1.Magnitude();
        const float resultWanted = glm::length(v2);

        if (myResult != resultWanted)
        {
            std::cout << "Fail on Math::Vector4::Magnitude" << std::endl;
            return false;
        }

        return true;
    }

    const bool TestUnitNormalizeVector4()
    {
        Math::Vector4<float> v1(1.f, 4.f, 9.f, 1.f);
        glm::vec4 v2(1.f, 4.f, 9.f, 1.f);

        const Math::Vector4 myResult = v1.Normalize();
        const glm::vec4 resultWanted = glm::normalize(v2);

        if (myResult.x != resultWanted.x && myResult.y != resultWanted.y && myResult.z != resultWanted.z && myResult.w != resultWanted.w)
        {
            std::cout << "Fail on Math::Vector4::Normalize" << std::endl;
            return false;
        }

        return true;
    }

    const bool TestUnitHomogenizeVector4()
    {
        Math::Vector4<float> v1(4.f, 4.f, 4.f, 2.f);

        v1.Homogenize();
        const Math::Vector4 resultWanted = Math::Vector4(2.f, 2.f, 2.f, 1.f);

        if (v1 != resultWanted)
        {
            std::cout << "Fail on Math::Vector4::Homogenize" << std::endl;
            return false;
        }

        return true;
    }

    const bool TestVector4()
    {
        if (TestUnitOperatorVector4() &&
            TestUnitDotProductVector4() &&
            TestUnitMagnitudeVector4() &&
            TestUnitHomogenizeVector4() &&
            TestUnitNormalizeVector4())
        {
            std::cout << "Vector4 : OK" << std::endl;
            return true;
        }
        std::cout << "Vector4 : Fail" << std::endl;
        return false;
    }
}