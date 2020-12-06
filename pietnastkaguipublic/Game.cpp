#include "Game.h"
#include "cstdlib"

void Game::randomizeFields()
{
	srand(time(NULL));
	std::vector<int> v;
	while (v.size() != 16) {
		int losowa = rand() % 16 + 1;
		if (notInVector(v, losowa)) {
			v.push_back(losowa);
		}
	}
	this->fields = { {v[0],v[1],v[2],v[3]},{v[4],v[5],v[6],v[7]},{v[8],v[9],v[10],v[11]},{v[12],v[13],v[14],v[15]} };
	//this->fields = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,16,15} };
}

bool Game::notInVector(std::vector<int> liczby, int a)
{
	int l = liczby.size();
	for (int i = 0; i < l; i++) {
		if (liczby[i] == a) {
			return false;
		}
	}
	return true;
}

std::vector<int> Game::checkCoordinates(int a)
{
	
	for (int i = 0; i < this->fields.size(); i++) {
		for (int j = 0; j < this->fields[i].size(); j++) {
			if (this->fields[i][j] == a) {
				std::vector<int> coords{ i, j };
				return coords;
			}
		}
	}
	std::vector<int> notInVectorBlock{ 1000,1000 };
	return notInVectorBlock;
}

bool Game::isPossible(int a)
{
	std::vector<int> wantedCoords = checkCoordinates(a);
	std::vector<int> blankCoords = checkCoordinates(16);
	if (blankCoords[0] + 1 == wantedCoords[0] || blankCoords[0] == wantedCoords[0] + 1) {
		if (blankCoords[1] == wantedCoords[1]) {
			return true;
		}
	}
	else if (blankCoords[1] + 1 == wantedCoords[1] || blankCoords[1] == wantedCoords[1] + 1) {
		if (blankCoords[0] == wantedCoords[0]) {
			return true;
		}
	}
	return false;
}

bool Game::checkWin()
{
	std::vector<std::vector<int>> winningPosition{ {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	if (this-> fields == winningPosition) {
		return true;
	}
	return false;
}
