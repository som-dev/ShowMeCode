///@file
///@brief Test subtleties with std::foreach()
/// This topic arose based on some unexpected behavior from a co-worker.
/// The main takeaway is the functor is pass-by-value so don't expect it
/// to save any result unless you 

#include <algorithm>
#include <vector>
#include <iostream>

class Algo
{
public:
	Algo() : sum(0)						{ std::cout << "  Default Constructor" << std::endl; }
	Algo(const Algo& a) : sum(a.sum)	{ std::cout << "  Copy Constructor" << std::endl; }
	Algo(const Algo&& a) : sum(a.sum)	{ std::cout << "  Move Constructor" << std::endl; }
	Algo& operator=(const Algo& a)		{ std::cout << "  Copy Assignment Operator" << std::endl; sum = a.sum; return *this; }
	Algo& operator=(const Algo&& a)		{ std::cout << "  Move Assignment Operator" << std::endl; sum = a.sum; return *this; }
	void operator()(int i)        	    { std::cout << "  Visiting " << i << std::endl; sum += i; }
	int GetSum() const					{ return sum; }
protected:
	mutable int sum;
};

class AlgoForRun2 : public Algo
{
public:
	void operator()(int i) const        { std::cout << "  Visiting " << i << std::endl; sum += i; }
protected:
	mutable int sum; // only mutable for operator()(int i) to be const
                     // which allows run2 example to compile
};

void StdForEach()
{
	std::vector<int> v = { 1, 2, 3 };

	// Run1: At first glance, one would expect this to return the sum but it doesn't.
	// The reason is the function object is passed in by value so it makes a copy and
	// operate on the copy.  The original is retained when the function is returned.
	std::cout << "Run1 starting..." << std::endl;
	Algo run1;
	std::for_each(v.begin(), v.end(), run1);
	std::cout << "Run1 result: " << run1.GetSum() << std::endl;

	// Run2: We can fix Run1 by instructing std::for_each() to accept the function
    // object by const reference but this also means operator() needs to be const
    // which doesn't make sense.
	std::cout << "Run2 starting..." << std::endl;
	AlgoForRun2 run2;
	std::for_each< std::vector<int>::iterator, const AlgoForRun2& >(v.begin(), v.end(), run2);
	std::cout << "Run2 result: " << run2.GetSum() << std::endl;
	
	// Run3: Run2 syntax is a bit clumsy and is not const correct.  We can
    // improve by storing the copy returned by for_each() back into the
    // original function object.  However, there are a lot of extra constructors called.
	std::cout << "Run3 starting..." << std::endl;
	Algo run3;
	run3 = std::for_each(v.begin(), v.end(), run3);
	std::cout << "Run3 result: " << run3.GetSum() << std::endl;

	// Run4: We elimiante an extra constructor and assignment call by passing the
	// function object directly into for_each() and using the move constructor
	std::cout << "Run4 starting..." << std::endl;
	auto run4 = std::for_each(v.begin(), v.end(), Algo());
	std::cout << "Run4 result: " << run4.GetSum() << std::endl;
	
}