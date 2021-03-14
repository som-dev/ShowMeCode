///@file
///@brief Illustrates types with various operators

#include <iostream>
#include <type_traits>
#include <cxxabi.h>
#include <typeinfo>
#include <memory>
#include <string>
#include <cstdlib>
#include <cstring>

template <class T>
std::string type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own(
        abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr),
        std::free);
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

#define SHOW(x) std::cout << #x": " << type_name<decltype(x)>() << ": " << x << std::endl;
void Types()
{
    char    abc[27]; 
    char    *ptr = abc; 
    strcpy(abc, "abcdefgxyz");
    
    SHOW(abc);
    SHOW(*abc);
    SHOW(abc[2]);
    SHOW(&abc[3]);
    SHOW(abc+4);
    SHOW(*(abc+5) + 20000);
    SHOW(abc[10]);
    SHOW(abc[12]);
    SHOW(&ptr);
}