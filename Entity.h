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
public:

	int playerOwner;

	int shoot(int x, int y);

	bool move(int x, int y);

	bool isInRange(int x, int y, int range);

	virtual int getValue() = 0;

	int takeDamage(int damage);

	bool init(Grid* g, int x, int y, int player);

	virtual ~Entity();

};