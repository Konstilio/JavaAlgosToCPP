#include"Algorithm.h"

int main()
{
	// Compile time! (supported by modern compilers only)
	static_assert(Algorithm::gcdRecursive(30,100) == 10, "Wrong!");
	static_assert(Algorithm::gcdRecursive(9,3) == 3, "Wrong!");
	return 0;
}