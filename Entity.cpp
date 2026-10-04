#include <iostream>
#include <stdlib.h>
#include "Grid.h"
#include "Entity.h"



bool Entity::init(Grid* g, int x, int y, int player) {
	pGrid = g;
	if (!pGrid->isCellInGrid(x, y) || pGrid->grid[y][x] != nullptr) {
		return false;
	}
	playerOwner = player;
	pGrid->grid[y][x] = this;
	pGrid = g;
	posx = x;
	posy = y;
	return true;
}

Entity::~Entity()
{
	pGrid->grid[posy][posx] = nullptr;
}

int Entity::shoot( int x, int y) {
	if (isInRange(x, y, shootRange)) {
		std::cout << "Case hors de portée. \n";
		return -2;
	}
	if (pGrid->grid[y][x] != nullptr) {
		std::cout << "Touche! \n";

		return pGrid->grid[y][x]->takeDamage(dmg);
		
	}
	else {
		std::cout << "Rate... \n";
	}
	return -1;
}

bool Entity::move( int x, int y) {
	if (isInRange(x,y,moveRange)) {
		std::cout << "Case hors de portee. \n";
		return false;
	}
	if (pGrid->grid[y][x] != nullptr) {
		std::cout << "Case deja occupée. \n";
		return false;
	}
	pGrid->grid[y][x] = this;
	pGrid->grid[posy][posx] = nullptr;
	posx = x;
	posy = y;
	return true;
}

bool Entity::isInRange(int x, int y, int range)
{
	return (abs(x - posx) + abs(y - posy) > range);
}

int Entity::takeDamage(int damage) {
	hp -= damage;
	if (hp < 0) {
		hp = 0;
		std::cout << "Unite detruite. \n";
	}
	else {
		std::cout << damage << " degats ont ete infliges \n";
	}
	return hp;
}

