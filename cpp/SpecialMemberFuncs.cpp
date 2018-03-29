/// @file
/// @brief Special member functions in C++ are functions which the compiler
/// will automatically generate if they are used, but not declared explicitly

/// It would be good to remind the reader of the Rule of Three here, that if
/// you need to provide either a copy constructor, copy assignment, or destructor
/// then you likely need all three.

/// With c++ 11 move semantics this extends to the Rule of Five as you may want
/// to provide the move constructor and move assignment, although these would
/// be optimizations.

#include <iostream>

class A
{
public:
    A() : v(0)                    { std::cout << "  Default Constructor" << std::endl; }
    A(const A& d) : v(d.v)        { std::cout << "  Copy Constructor" << std::endl; }
    A(const A&& d) : v(d.v)        { std::cout << "  Move Constructor" << std::endl; }
    A& operator=(const A& d)    { std::cout << "  Copy Assignment Operator" << std::endl; v = d.v; return *this; }
    A& operator=(const A&& d)    { std::cout << "  Move Assignment Operator" << std::endl; v = d.v; return *this; }
    ~A()                        { std::cout << "  Destructor" << std::endl; }
protected:
    int v;
};

class B
{
    A a;
};

/// @brief Run the tests
void SpecialMemberFuncs()
{
    B b1;
    B b2 = b1;
    b1 = b2;
    B b3 = std::move(b1);
    b3 = std::move(b2);
}
