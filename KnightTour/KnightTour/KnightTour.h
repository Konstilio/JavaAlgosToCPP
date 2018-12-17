#pragma once
#include <vector>
#include <array>
using std::vector;
class KnightTour
{
	vector<vector<int>> solutionMatrix;
	constexpr static std::array<int, 8> xMoves = { 2, 1, -1, -2, -2, -1, 1, 2 };
	constexpr static std::array<int, 8> yMoves = { 1, 2, 2, 1, -1, -2, -2, -1 };

	constexpr static int BOARD_SIZE = 7;

public:
	KnightTour();

	void solveKnightTourProblem();
	bool solveProblem(int stepCount, int x, int y);

	bool isValidMove(int x, int y);

	void showSolution();

private:

	void initializeBoard();
};

