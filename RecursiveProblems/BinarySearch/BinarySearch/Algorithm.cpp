#include "Algorithm.h"

Algorithm::Algorithm(const vector<int> &_nums)
	: nums(_nums)
{
}

int Algorithm::linearSearch(int item) const
{
	for (size_t i = 0; i < nums.size(); ++i) {
		if (item == nums[i]) {
			return i;
		}
	}

	return -1;
}

int Algorithm::binarySearch(int item) const
{
	return binarySearch(0, nums.size() - 1, item);
}

int Algorithm::binarySearch(int startIndex, int endIndex, int item) const
{
	if (endIndex < startIndex)
		return -1;

	int middleIndex = (startIndex + endIndex) / 2;

	if (item == nums[middleIndex])
		return middleIndex;
	else if (item < nums[middleIndex])
		return binarySearch(startIndex, middleIndex - 1, item);
	else
		return binarySearch(middleIndex + 1, endIndex, item);
}
