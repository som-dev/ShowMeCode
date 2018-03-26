/// @file
/// @brief Old-school ways to access arrays that I had to try to believe

#include <iostream>

void Array()
{
    int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    std::cout << "(0)[array]=" << (0)[array] << std::endl;
    std::cout << "(array)[0]=" << (array)[0] << std::endl;
    std::cout << "(1 + 3)[array]=" << (1 + 3)[array] << std::endl;
    std::cout << "(array)[1+3]=" << (array)[1+3] << std::endl;
    std::cout << "(array + 3)[2]=" << (array + 3)[2] << std::endl;
}
