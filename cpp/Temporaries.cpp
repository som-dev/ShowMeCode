/// @file
/// @brief Illustrates when a reference to a temporary variable
/// can extend the life of the temporary.  Also shows how
/// derived classes behave as expected.

#include <deque>
#include <iostream>

class PlainClass
{
public:
    PlainClass(const std::string& id) : m_id(id)
    {
        std::cout << "PlainClass constructor " << m_id << std::endl;
    }
    virtual ~PlainClass()
    {
        std::cout << "PlainClass destructor " << m_id << std::endl;
    }
    std::string m_id;
};

class DerivedClass : public PlainClass
{
public:
    DerivedClass(const std::string& id) : PlainClass(id), m_id(id)
    {
        std::cout << "DerivedClass constructor " << m_id << std::endl;
    }
    virtual ~DerivedClass()
    {
        std::cout << "DerivedClass destructor " << m_id << std::endl;
    }
    std::string m_id;
};


PlainClass GetPlainClass(const std::string& id)
{
    return PlainClass(id);
}

DerivedClass GetDerivedClass(const std::string& id)
{
    return DerivedClass(id);
}

void Temporaries()
{
    {
        const auto& ConstRefToPlainClass = GetPlainClass("ConstRefToPlainClass");
        std::cout << "Using " << ConstRefToPlainClass.m_id << std::endl;
    }

    std::cout << std::endl;
    
    {
        auto&& NonConstRValueRefToPlainClass = GetPlainClass("NonConstRValueRefToPlainClass");
        std::cout << "Using " << NonConstRValueRefToPlainClass.m_id << std::endl;
    }

    std::cout << std::endl;
    
    {
        const auto&& ConstRValueRefToPlainClass = GetPlainClass("ConstRValueRefToPlainClass");
        std::cout << "Using " << ConstRValueRefToPlainClass.m_id << std::endl;
    }

    // auto& NonConstRefToPlainClass = GetPlainClass("auto&"); // compiler error with gcc - needs const

    std::cout << std::endl;

    {
        const PlainClass& ConstRefToDerivedClass = GetDerivedClass("ConstRefToDerivedClass");
        std::cout << "Using " << ConstRefToDerivedClass.m_id << std::endl;
    }

}
