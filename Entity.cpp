#include <iostream>
#include <stdlib.h>
#include "Grid.h"
#include "Entity.h"



bool Entity::init(Grid& g, int x, int y) {
	if (!g.isCellValid(x, y) || g.grid[x][y] != nullptr) {
		return false;
	}
	g.grid[x][y] = this;
	posx = x;
	posy = y;
	return true;
}

void Entity::shoot(Grid& g, int x, int y) {
	if (!g.isCellValid(x, y)) return;
	if (g.grid[x][y] != nullptr) {
		std::cout << "Touche! \n";

		g.grid[x][y]->takeDamage(dmg);
		
	}
}

bool Entity::move(Grid& g, int x, int y) {
	if (abs(x - posx) + abs(y - posy) > moveRange) {
		return false;
	}
	if (g.grid[x][y] != nullptr) {
		return false;
	}
	g.grid[x][y] = this;
	g.grid[posx][posy] = nullptr;
	posx = x;
	posy = y;
	return true;
}

void Entity::takeDamage(int damage) {
	hp -= damage;
	if (hp < 0) {
		hp = 0;
	}
	std::cout << damage << " degats ont ete infliges \n";
}