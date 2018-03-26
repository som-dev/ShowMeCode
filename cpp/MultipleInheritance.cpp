/// @file
/// @brief Illustrates the diamond problem issue with multiple inheritance

#include <iostream>
#include <string>

class Base
{
public:
    virtual void GetRoleAll()               { std::cout << "Base" << std::endl; }
    virtual void getRoleBaseOnly()          { std::cout << "Base" << std::endl; }
};

class DerivedA : public Base
{
public:
    virtual void GetRoleAll()               { std::cout << "DerivedA" << std::endl; }
    virtual void GetRoleDerivedBothAandB()  { std::cout << "DerivedA" << std::endl; }
    virtual void GetRoleDerivedAOnly()      { std::cout << "DerivedA" << std::endl; }
};

class DerivedB : public Base
{
public:
    virtual void GetRoleAll()               { std::cout << "DerivedB" << std::endl; }
    virtual void GetRoleDerivedBothAandB()  { std::cout << "DerivedB" << std::endl; }
    virtual void GetRoleDerivedBOnly()      { std::cout << "DerivedB" << std::endl; }
};

class InheritFromBothV1 : public DerivedA, public DerivedB
{
public:
    virtual void GetRoleAll()               { std::cout << "InheritFromBothV1" << std::endl; }
};

class VirtualDerivedA : virtual public Base
{
public:
    virtual void GetRoleAll()               { std::cout << "VirtualDerivedA" << std::endl; }
    virtual void GetRoleDerivedBothAandB()  { std::cout << "VirtualDerivedA" << std::endl; }
    virtual void GetRoleDerivedAOnly()      { std::cout << "VirtualDerivedA" << std::endl; }
};

class VirtualDerivedB : virtual public Base
{
public:
    virtual void GetRoleAll()               { std::cout << "VirtualDerivedB" << std::endl; }
    virtual void GetRoleDerivedBothAandB()  { std::cout << "VirtualDerivedB" << std::endl; }
    virtual void GetRoleDerivedBOnly()      { std::cout << "VirtualDerivedB" << std::endl; }
};

class InheritFromBothVirtually : public VirtualDerivedA, public VirtualDerivedB
{
public:
    virtual void GetRoleAll() { std::cout << "InheritFromBothVirtually" << std::endl; }
};

/// @brief 
void MultipleInheritance()
{
    InheritFromBothV1 v1;
    v1.GetRoleAll();
    //v1.getRoleBaseOnly();         // compiler error: request for member ‘getRole’ is ambiguous
    //v1.GetRoleDerivedBothAandB(); // compiler error: request for member ‘getRole’ is ambiguous
    v1.GetRoleDerivedAOnly();
    v1.GetRoleDerivedBOnly();

    InheritFromBothVirtually v2;
    v2.GetRoleAll();
    v2.getRoleBaseOnly();
    //v2.GetRoleDerivedBothAandB(); // compiler error: request for member ‘getRole’ is ambiguous
    v2.GetRoleDerivedAOnly();
    v2.GetRoleDerivedBOnly();
}
