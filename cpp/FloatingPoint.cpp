/// @file
/// @brief Demonstrate various behaviors of floating point issues

#include <iostream>

/// @brief Run the tests
void FloatingPoint()
{
    float f1 = 1.1 + 2.2 + 3.3;
    float f2 = 3.3 + 1.1 + 2.2;
    bool fIsEqual = (f1 == f2);
    std::cout << "f1 == f2: " << fIsEqual << std::endl;

    double d1 = 1.1 + 2.2 + 3.3;
    double d2 = 3.3 + 1.1 + 2.2;
    bool dIsEqual = (d1 == d2);
    std::cout << "d1 == d2: " << dIsEqual << std::endl;
}
