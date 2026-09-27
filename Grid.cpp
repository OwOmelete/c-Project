#include <iostream>
#include "Grid.h"


bool Grid::isCellValid(int x, int y) {
	if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y]!=nullptr) {
		return false;
	}
	return true;
}

void Grid::displayGrid() {
	for (int i = row-1; i >-1; i--) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == nullptr) {
				std::cout << 0;
			}
			else {
				int n = grid[i][j]->getValue();
				std::cout << n;
			}
		}
		std::cout << "\n";
	}
}