/// @file
/// @brief Test how the compiler treats pointers to string literals
/// This topic arose while reviewing interview questions. Not many co-workers realized
/// that string literals would be stored in a read-only area of the program
/// and that one could write to this area but would crash the program.
/// Further, this helped illustrate what the compiler would allow or deny
/// for const pointers or pointers to const data, both, or neither.

/// @brief Helper method to write data to the location pointed by the pointer ptr
template<typename PtrType>
void WriteToPointedLocation(PtrType ptr)
{
	*ptr = 'A';
}

/// @brief Helper method to modify where the pointer ptr points to
template<typename PtrType>
void ModifyPtr(PtrType& ptr)
{
	ptr++;
}

/// @brief Run the tests
void StringLiterals()
{
	char* PtrToChar = "Literal1";						// compiler warning: ISO C++ forbids converting a string constant to ‘char*
	// WriteToPointedLocation(PtrToChar);				// runtime error: Program received signal SIGSEGV, Segmentation fault
	ModifyPtr(PtrToChar);

	const char* PtrToConstChar = "Literal2";
	// WriteToPointedLocation(PtrToConstChar);			// compiler error: assignment of read-only location
	ModifyPtr(PtrToConstChar);
	
	char const * PtrToConstCharAltForm = "Literal3";
	// WriteToPointedLocation(PtrToConstCharAltForm);	// compiler error: assignment of read-only location
	ModifyPtr(PtrToConstCharAltForm);
	
	char* const ConstPtrToChar = "Literal4";			// compiler warning: ISO C++ forbids converting a string constant to ‘char*
	// WriteToPointedLocation(ConstPtrToChar);			// runtime error: Program received signal SIGSEGV, Segmentation fault
	// ModifyPtr(ConstPtrToChar);						// compiler error: increment of read-only variable
	
	const char* const ConstPtrToConstChar = "Literal5";
	// WriteToPointedLocation(ConstPtrToConstChar);		// compiler error: assignment of read-only location
	// ModifyPtr(ConstPtrToConstChar);					// compiler error: increment of read-only variable
	
	char const * const ConstPtrToConstCharAltForm = "Literal6";
	// WriteToPointedLocation(ConstPtrToConstCharAltForm);	// compiler error: assignment of read-only location
	// ModifyPtr(ConstPtrToConstCharAltForm);				// compiler error: increment of read-only variable
	
	char PtrToCharArray[] = "LiteralA";
	WriteToPointedLocation(PtrToCharArray);
	// ModifyPtr(PtrToCharArray);						// compiler error: increment of read-only location

	const char PtrToConstCharArray[] = "LiteralB";
	// WriteToPointedLocation(PtrToConstCharArray);		// compiler error: assignment of read-only location
	// ModifyPtr(PtrToConstCharArray);					// compiler error: increment of read-only location 

	char const PtrToConstCharArrayAltForm[] = "LiteralC";
	// WriteToPointedLocation(PtrToConstCharArrayAltForm);	// compiler error: assignment of read-only location
	// ModifyPtr(PtrToConstCharArrayAltForm);			    // compiler error: increment of read-only location
}
