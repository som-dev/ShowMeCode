///@file
///@brief Illustrates simple tuple usage

#include <iostream>
#include <tuple>

void Tuple()
{
    using UserData = std::tuple<
        std::string,    // name
        unsigned int,   // id
        std::string>;   // email
    enum UserDataFields { nameField, idField, emailField };
    
    UserData ud = std::make_tuple("John Doe", 1234, "j@doe.com");
    
    std::cout << "Name="  << std::get<nameField>(ud)
              << ",Id="    << std::get<idField>(ud)
              << ",Email=" << std::get<emailField>(ud)
              << std::endl;

    std::string name;
    unsigned int id;
    std::string email;
    std::tie(name, id, email) = ud;
    
    std::cout << "Name="  << name
              << ",Id="    << id
              << ",Email=" << email
              << std::endl;

    
}