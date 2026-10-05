#pragma once
#include "Grid.h"
#include <iostream>

class Grid;

class Entity {
protected:
	int hp;
	int dmg;
	int moveRange;
	int shootRange;
	int posx = 0;
	int posy = 0;
	Grid* pGrid;
	char name;
public:

	int playerOwner;

	virtual bool shoot(int x, int y);

	virtual bool move(int x, int y);

	bool isInRange(int x, int y, int range);

	virtual char getName() = 0;

	void takeDamage(int damage);

	void heal(int healing);

	bool init(Grid* g, int x, int y, int player);

	virtual ~Entity();

	bool isAlive();
};