/// @file
/// @brief Illustrates behaviors when an exception is thrown.  The control should pass
/// from the try-block to the catch-block (exception handler).  Before the catch-block is
/// executed, all stack objects constructed since the beginning of the try block should
/// be destructed in reverse order. This is called stack unwinding.

/// Reminder to perfer throw an exception by value and catch by reference or const reference
/// when possible.

#include <iostream>
#include <memory>

/// @brief Helper class to illustrate stack unwinding
class PlainClass
{
public:
    PlainClass(const std::string& id) : m_id(id)
    {
        std::cout << "PlainClass() " << m_id << std::endl;
    }
    virtual ~PlainClass()
    {
        std::cout << "~PlainClass() " << m_id << std::endl;
    }
    std::string m_id;
};

/// @brief Helper class to illustrate stack unwinding from constructor
class ThrowFromConstructor : public PlainClass
{
public:
    ThrowFromConstructor(const std::string& id)
        : PlainClass("Inherited PlainClass"),
        m_HasAPlainClass("Composition PlainClass"),
        m_id(id)
    {
        std::cout << "ThrowFromConstructor() " << m_id << std::endl;
        throw 1;
    }
    virtual ~ThrowFromConstructor()
    {
        std::cout << "Should not reach this: ~ThrowFromConstructor() " << m_id << std::endl;
    }
    PlainClass m_HasAPlainClass;
    std::string m_id;
};

/// @brief Helper class to illustrate the never-throw-from-destructor concept
class ThrowFromDestructor
{
public:
    ThrowFromDestructor(const std::string& id) : m_id(id)
    {
        std::cout << "ThrowFromDestructor() " << m_id << std::endl;
    }
    virtual ~ThrowFromDestructor()
    {
        std::cout << "~ThrowFromDestructor() " << m_id << std::endl;
        throw 1; // This is bad
    }
    std::string m_id;
};

/// @brief Run the tests
void Exceptions()
{
    try
    {
        PlainClass outer("Stack-allocated Outer Try");
        auto ptr_outer = std::make_shared<PlainClass>("Smart-pointer Outer Try");
        try
        {
            PlainClass inner("Stack-allocated Inner Try");
            auto ptr_inner = std::make_shared<PlainClass>("Smart-pointer Inner Try");
            throw 1;
            std::cout << "Should not reach this line" << std::endl;
        }
        catch (int i)
        {
            std::cout << "Inner Catch.  Objects in Inner try should be unwound." << std::endl;
            throw;
        }
        std::cout << "Should not reach this line" << std::endl;
    }
    catch (int i)
    {
        std::cout << "Outer Catch.  Objects in Outer try should be unwound." << std::endl;
    }

    std::cout << std::endl;
    try
    {
        ThrowFromConstructor tfc("ThrowFromConstructor");
        throw 1;
        std::cout << "Should not reach this line" << std::endl;
    }
    catch (int i)
    {
        std::cout << "Catch. Objects should be unwound." << std::endl;
    }

    std::cout << std::endl;
    try
    {
        ThrowFromDestructor ba("Bad Actor");
        throw 1;
    }
    catch (int i)
    {
        std::cout << "Program should abruptly terminate() before reaching this line" << std::endl;
    }
}
