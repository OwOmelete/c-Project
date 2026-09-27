#pragma once
#include "Grid.h"

class Grid;

class Entity {
protected:
	int hp;
	int dmg;
	int moveRange;
	int posx = 0;
	int posy = 0;
public:

	void shoot(Grid& g, int x, int y);

	bool move(Grid& g, int x, int y);

	virtual int getValue() = 0;

	void takeDamage(int damage);

	bool init(Grid& g, int x, int y);

};