#include <iostream>

#include "../Header/UnitTestVector2.hpp"
#include "../Header/UnitTestVector3.hpp"
#include "../Header/UnitTestVector4.hpp"
#include "../Header/UnitTestMat4x4.hpp"

const bool UnitTestMath()
{
    if (UnitTest::TestVector2() &&
        UnitTest::TestVector3() &&
        UnitTest::TestVector4() &&
        UnitTest::TestMat4x4())
    {
        std::cout << "Math : OK" << std::endl;
        return true;
    }
    std::cout << "Math : Fail" << std::endl;
    return false;
}

int main()
{
    UnitTestMath();
}
