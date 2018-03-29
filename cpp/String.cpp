/// @file
/// @brief Demonstrate various behaviors of std::string

#include <string>
#include <iostream>

/// @brief Run the tests
void String()
{
    char* null = nullptr;
    try
    {
        std::string strFromNull(null);
    }
    catch (std::exception& ex)
    {
        std::cout << "strFromNull caught " << ex.what() << std::endl;
    }
}
