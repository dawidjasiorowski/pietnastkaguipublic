#pragma once
#include "vector"
#include "time.h"

class Game
{
public:
	std::vector<std::vector<int>> fields;

	void randomizeFields();
	bool notInVector(std::vector<int> liczby, int a);
	std::vector<int> checkCoordinates(int a);
	bool isPossible(int a);
	bool checkWin();
};

