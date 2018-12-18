#include"Algorithm.h"

int main()
{
	// Compile time! (supported by modern compilers only)
	static_assert(Algorithm::factorial(8) == 40320LL, "Wrong!");
	static_assert(Algorithm::factorialIterative(9) == 362880LL, "Wrong!");
	return 0;
}