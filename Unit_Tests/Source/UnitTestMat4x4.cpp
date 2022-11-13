#include "../Header/UnitTestMat4x4.hpp"

#include "../../Math/Mat4x4.hpp"
#include"../Libs/glm/matrix.hpp"
#include"../Libs/glm/gtc/matrix_transform.hpp"

namespace UnitTest
{
    Math::Mat4x4<float> GlmMatToMat(const glm::mat4x4& mat)
    {
        return Math::Mat4x4<float>(
            mat[0][0], mat[1][0], mat[2][0], mat[3][0],
            mat[0][1], mat[1][1], mat[2][1], mat[3][1],
            mat[0][2], mat[1][2], mat[2][2], mat[3][2],
            mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
    }

    Math::Vector4<float> GlmVecToVec(const glm::vec4& vec)
    {
        return Math::Vector4<float>(vec.x, vec.y, vec.z, vec.w);
    }

    Math::Vector3<float> GlmVecToVec(const glm::vec3& vec)
    {
        return Math::Vector3<float>(vec.x, vec.y, vec.z);
    }

    bool TestOperatorMat4x4()
    {
        glm::mat4 mat1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);
        glm::mat4 mat2(16.f, 15.f, 14.f, 13.f, 12.f, 11.f, 10.f, 9.f, 8.f, 7.f, 6.f, 5.f, 4.f, 3.f, 2.f, 1.f);

        // Operator +
        Math::Mat4x4 result = GlmMatToMat(mat1 + mat2);
        if ((GlmMatToMat(mat1) + GlmMatToMat(mat2)) != result)
        {
            std::cout << "Fail on Math::Mat4x4 Operator+" << std::endl;
            return false;
        }

        // Operator -
        result = GlmMatToMat(mat1 - mat2);
        if ((GlmMatToMat(mat1) - GlmMatToMat(mat2)) != result)
        {
            std::cout << "Fail on Math::Mat4x4 Operator-" << std::endl;
            return false;
        }

        // Operator * Mat4x4
        result = GlmMatToMat(mat1 * mat2);
        if ((GlmMatToMat(mat1) * GlmMatToMat(mat2)) != result)
        {
            std::cout << "Fail on Math::Mat4x4 Operator* Mat4x4" << std::endl;
            return false;
        }

        glm::vec4 vec(2.f, 2.f, 2.f, 2.f);

        // Operator * Vector4
        if ((GlmMatToMat(mat1) * GlmVecToVec(vec)) != GlmVecToVec(mat1 * vec))
        {
            std::cout << "Fail on Math::Mat4x4 Operator* Vector4" << std::endl;
            return false;
        }

        return true;
    }
    
    bool TestTranslationMat4x4()
    {
        glm::mat4 mat(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);
        glm::vec3 vec(1.f, 2.f, 3.f);

        Math::Mat4x4 myResult = GlmMatToMat(mat) * Math::Mat4x4<float>::CreateTranslationMatrix(GlmVecToVec(vec));
        Math::Mat4x4 glmResult = GlmMatToMat(glm::translate(mat, vec));

        if(myResult != glmResult)
        {
            std::cout << "Fail on Math::Mat4x4 CreateTranslationMatrix" << std::endl;
            return false;
        }

        return true;
    }

    bool TestRotationXMat4x4()
    {
        glm::mat4 mat(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);

        Math::Mat4x4 myResult = GlmMatToMat(mat) * Math::Mat4x4<float>::CreateXRotationMatrix(90.f);
        Math::Mat4x4 glmResult = GlmMatToMat(glm::rotate(mat, glm::radians(90.f), { 1.f, 0.f, 0.f }));

        if (myResult != glmResult)
        {
            std::cout << "Fail on Math::Mat4x4 CreateXRotationMatrix" << std::endl;
            return false;
        }

        return true;
    }

    bool TestRotationYMat4x4()
    {
        glm::mat4 mat(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);

        Math::Mat4x4 myResult = GlmMatToMat(mat) * Math::Mat4x4<float>::CreateYRotationMatrix(90.f);
        Math::Mat4x4 glmResult = GlmMatToMat(glm::rotate(mat, glm::radians(90.f), { 0.f, 1.f, 0.f }));

        if (myResult != glmResult)
        {
            std::cout << "Fail on Math::Mat4x4 CreateYRotationMatrix" << std::endl;
            return false;
        }

        return true;
    }

    bool TestRotationZMat4x4()
    {
        glm::mat4 mat(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);

        Math::Mat4x4 myResult = GlmMatToMat(mat) * Math::Mat4x4<float>::CreateZRotationMatrix(90.f);
        Math::Mat4x4 glmResult = GlmMatToMat(glm::rotate(mat, glm::radians(90.f), { 0.f, 0.f, 1.f }));

        if (myResult != glmResult)
        {
            std::cout << "Fail on Math::Mat4x4 CreateZRotationMatrix" << std::endl;
            return false;
        }

        return true;
    }

    bool TestScaleMat4x4()
    {
        glm::mat4 mat(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);
        glm::vec3 scale(1.f, 2.f, 3.f);

        Math::Mat4x4 myResult = GlmMatToMat(mat) * Math::Mat4x4<float>::CreateScaleMatrix(GlmVecToVec(scale));
        Math::Mat4x4 glmResult = GlmMatToMat(glm::scale(mat, scale));

        if (myResult != glmResult)
        {
            std::cout << "Fail on Math::Mat4x4 CreateScaleMatrix" << std::endl;
            return false;
        }

        return true;
    }

    const bool TestMat4x4()
    {
        if (TestOperatorMat4x4() &&
            TestTranslationMat4x4() &&
            TestRotationXMat4x4() &&
            TestRotationYMat4x4() &&
            TestRotationZMat4x4() && 
            TestScaleMat4x4())
        {
            std::cout << "Mat4x4 : OK" << std::endl;
            return true;
        }
        std::cout << "Mat4x4 : Fail" << std::endl;
        return false;
    }
}
