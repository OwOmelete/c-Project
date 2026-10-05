#pragma once
#include "Entity.h"

constexpr int row = 10;
constexpr int col = 10;

class Entity;

class Grid{
	public :
		Entity* grid[row][col] = {};

		//Entity getGridCell(int x, int y);
		bool isCellInGrid(int x, int y);
		bool isCellOccupied(int x, int y);

		void displayGrid();
};