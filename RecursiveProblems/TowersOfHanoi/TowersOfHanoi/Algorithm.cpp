#include "Algorithm.h"
#include <iostream>
using std::cout;

void Algorithm::solveHanoiProblem(int n, char rodFrom, char middleRod, char rodTo)
{
	if (n == 1) {
		cout << "Plate 1 from " << rodFrom << " to " << rodTo << '\n';
		return;
	}

	solveHanoiProblem(n - 1, rodFrom, rodTo, middleRod);
	cout <<  "Plate " << n << " from " << rodFrom << " to " << rodTo << '\n';
	solveHanoiProblem(n - 1, middleRod, rodFrom, rodTo);
}

