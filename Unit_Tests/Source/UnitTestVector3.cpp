#include "../Header/UnitTestVector3.hpp"

#include "../../Math/Vector3.hpp"
#include "../Libs/glm/vec3.hpp"
#include "../Libs/glm/geometric.hpp"

namespace UnitTest
{
    const bool TestUnitOperatorVector3()
    {
        // Operator +
        if ((Math::Vector3(1.f, 1.f, 1.f) + Math::Vector3(1.f, 1.f, 1.f)) != Math::Vector3(2.f, 2.f, 2.f))
        {
            std::cout << "Fail on Math::Vector3 Operator + " << std::endl;
            return false;
        }

        // Operator -
        if ((Math::Vector3(1.f, 1.f, 1.f) - Math::Vector3(1.f, 1.f, 1.f)) != Math::Vector3(0.f, 0.f, 0.f))
        {
            std::cout << "Fail on Math::Vector3 Operator - " << std::endl;
            return false;
        }

        // Operator *
        if ((Math::Vector3(1.f, 1.f, 1.f) * 2.f) != Math::Vector3(2.f, 2.f, 2.f))
        {
            std::cout << "Fail on Math::Vector3 Operator * " << std::endl;
            return false;
        }

        // Operator /
        if ((Math::Vector3(2.f, 2.f, 2.f) / 2.f) != Math::Vector3(1.f, 1.f, 1.f))
        {
            std::cout << "Fail on Math::Vector3 Operator / " << std::endl;
            return false;
        }

        // Operator +=
        Math::Vector3 vector3 = Math::Vector3<float>(1.f, 1.f, 1.f);
        vector3 += Math::Vector3(1.f, 1.f, 1.f);
        if (vector3 != Math::Vector3(2.f, 2.f, 2.f))
        {
            std::cout << "Fail on Math::Vector3 Operator += " << std::endl;
            return false;
        }

        // Operator -=
        vector3 = Math::Vector3<float>(1.f, 1.f, 1.f);
        vector3 -= Math::Vector3(1.f, 1.f, 1.f);
        if (vector3 != Math::Vector3(0.f, 0.f, 0.f))
        {
            std::cout << "Fail on Math::Vector3 Operator -= " << std::endl;
            return false;
        }

        // Operator *=
        vector3 = Math::Vector3<float>(1.f, 1.f, 1.f);
        vector3 *= 2.f;
        if (vector3 != Math::Vector3(2.f, 2.f, 2.f))
        {
            std::cout << "Fail on Math::Vector3 Operator *= " << std::endl;
            return false;
        }

        // Operator /=
        vector3 = Math::Vector3<float>(2.f, 2.f, 2.f);
        vector3 /= 2.f;
        if (vector3 != Math::Vector3(1.f, 1.f, 1.f))
        {
            std::cout << "Fail on Math::Vector3 Operator /= " << std::endl;
            return false;
        }

        return true;
    }

    const bool TestUnitDotProductVector3()
    {
        Math::Vector3<float> v1(1.f, 4.f, 8.f);
        Math::Vector3<float> v2(2.f, 3.f, 7.f);
        glm::vec3 v3(1.f, 4.f, 8.f);
        glm::vec3 v4(2.f, 3.f, 7.f);

        const float myResult = v1.DotProduct(v2);
        const float resultWanted = glm::dot(v3, v4);

        if (myResult != resultWanted)
        {
            std::cout << "Fail on Math::Vector3::DotProduct" << std::endl;
            return false;
        }

        return true;
    }

    const bool TestUnitMagnitudeVector3()
    {
        Math::Vector3<float> v1(1.f, 4.f, 8.f);
        glm::vec3 v2(1.f, 4.f, 8.f);

        const float myResult = v1.Magnitude();
        const float resultWanted = glm::length(v2);

        if (myResult != resultWanted)
        {
            std::cout << "Fail on Math::Vector3::Magnitude" << std::endl;
            return false;
        }

        return true;
    }

    const bool TestUnitCrossProductVector3()
    {
        Math::Vector3<float> v1(5.f, 4.f, 1.f);
        Math::Vector3<float> v2(2.f, 3.f, 3.f);

        glm::vec3 v3(5.f, 4.f, 1.f);
        glm::vec3 v4(2.f, 3.f, 3.f);

        const Math::Vector3<float> myResult = v1.CrossProduct(v2);
        const Math::Vector3 resultWanted = Math::Vector3(glm::cross(v3, v4).x, glm::cross(v3, v4).y, glm::cross(v3, v4).z);

        if (myResult != resultWanted)
        {
            std::cout << "Fail on Math::Vector3::CrossProduct" << std::endl;
            return false;
        }

        return true;
    }

    const bool TestUnitNormalizeVector3()
    {
        Math::Vector3<float> v1(1.f, 4.f, 9.f);
        glm::vec3 v2(1.f, 4.f, 9.f);

        const Math::Vector3 myResult = v1.Normalize();
        const glm::vec3 resultWanted = glm::normalize(v2);

        if (myResult.x != resultWanted.x && myResult.y != resultWanted.y && myResult.z != resultWanted.z)
        {
            std::cout << "Fail on Math::Vector3::Normalize" << std::endl;
            return false;
        }

        return true;
    }

    const bool TestVector3()
    {
        if (TestUnitOperatorVector3() &&
            TestUnitDotProductVector3() &&
            TestUnitMagnitudeVector3() &&
            TestUnitCrossProductVector3() &&
            TestUnitNormalizeVector3())
        {
            std::cout << "Vector3 : OK" << std::endl;
            return true;
        }
        std::cout << "Vector3 : Fail" << std::endl;
        return false;
    }
}