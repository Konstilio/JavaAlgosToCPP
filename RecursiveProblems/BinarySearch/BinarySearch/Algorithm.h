#pragma once
#include <vector>
using std::vector;

class Algorithm
{
	vector<int> nums;
public:
	Algorithm(const vector<int> &_nums);

	int linearSearch(int item) const;
	int binarySearch(int item) const;

private:
	int binarySearch(int startIndex, int endIndex, int item) const;
};

