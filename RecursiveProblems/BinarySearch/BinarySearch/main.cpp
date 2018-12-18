#include "Algorithm.h"
#include <iostream>
using std::cout;

int main()
{
	vector<int> nums = { 1,5,6,8,13,22,26,40,50,57,60 };

	Algorithm algorithm{ nums };
	cout << algorithm.binarySearch(5) << '\n';
	return 0;
}