#include <iostream>
#include "Grid.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

bool Grid::isCellInGrid(int x, int y) {
	if (x < 0 || y < 0 || x >= col  || y >= row) {
		return false;
	}
	return true;

}

bool Grid::isCellOccupied(int x, int y) {
	return (grid[y][x] != nullptr);
}

void Grid::displayGrid() {
	for (int i = row-1; i >-1; i--) {
		std::cout << "|";
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == nullptr) {
				std::cout << "_";
			}
			else {
				char n = grid[i][j]->getName();
				int player = grid[i][j]->playerOwner;
				if (player == 1) {
					std::cout << RED << n << RESET;
				}
				else if(player == 2){
					std::cout << BLUE << n << RESET;
				}
				
			}
			std::cout << "|";
		}
		std::cout << "\n";
	}
}