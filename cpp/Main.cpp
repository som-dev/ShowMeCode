///@file
///@brief Registers each "Example" with the Registrar and operates a
/// simple command line menu loop to let the user pick an example.
/// To add a new one, declare the extern void() function and register
/// this function with the Registrar.

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <Registrar.hpp>

extern void StringLiterals();
extern void StdForEach();
extern void Exceptions();
extern void Temporaries();
extern void String();
extern void MultipleInheritance();
extern void Array();

void DisplayMenu(const Registrar& registrar);
bool GetSelection(unsigned int& selection);

int main()
{
	Registrar registrar;
	registrar.RegisterFunction("String Literals", Registrar::ExampleFunction(&StringLiterals));
	registrar.RegisterFunction("std::foreach", Registrar::ExampleFunction(&StdForEach));
	registrar.RegisterFunction("Exceptions", Registrar::ExampleFunction(&Exceptions));
	registrar.RegisterFunction("Temporaries", Registrar::ExampleFunction(&Temporaries));
	registrar.RegisterFunction("String", Registrar::ExampleFunction(&String));
	registrar.RegisterFunction("Multiple Inheritance", Registrar::ExampleFunction(&MultipleInheritance));
	registrar.RegisterFunction("Array", Registrar::ExampleFunction(&Array));

	while (true)
	{
		DisplayMenu(registrar);
		unsigned int selection;
		if (!GetSelection(selection))
 		{
			std::cout << "Quitting..." << std::endl;
			break;
		}
		else if (selection < registrar.Size() + 1) // compensate for starting at item 1
		{
			selection -= 1;
			std::cout << "Running " << registrar.GetName(selection) << "..." << std::endl << std::endl;
			registrar.Invoke(selection);
		}
		else
		{
			std::cout << selection << " is not a valid example. Please try again." << std::endl;
		}
	}
		
	return 0;
}

void DisplayMenu(const Registrar& registrar)
{
	std::cout << std::endl << "Select an example or Q to quit:" << std::endl;
	for (auto i = 0; i < registrar.Size(); ++i)
	{
		std::cout << i+1 << ": " << registrar.GetName(i) << std::endl;
	}
	std::cout << "Q: Quit" << std::endl;
}

bool GetSelection(unsigned int& selection)
{
	std::string input;
	std::cin >> input;
	std::cin.ignore();
	std::cout << std::endl;
	if (input.length() > 0 && std::toupper(input[0]) == 'Q')
	{
		return false;
	}
	selection = atoi(input.c_str());
	return true;
}


