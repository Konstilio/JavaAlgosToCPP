#include"Algorithm.h"

int main()
{
	// Compile time! (supported by modern compilers only)
	static_assert(Algorithm::sumIterative(10) == 55, "Wrong!");
	static_assert(Algorithm::sumRecursive(9) == 45, "Wrong!");
	return 0;
}