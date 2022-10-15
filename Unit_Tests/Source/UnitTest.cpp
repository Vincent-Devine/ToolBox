#include <iostream>

#include "../Header/UnitTestVector2.hpp"

const bool UnitTestMath()
{
    if (UnitTest::TestVector2())
        return true;
    return false;
}

int main()
{
    if (UnitTestMath())
        std::cout << "Math : OK" << std::endl;
}
