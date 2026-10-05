#include "Healer.h"

Healer::Healer() : Entity()
{
	hp = baseHp;
	dmg = baseDmg;
	moveRange = baseMoveRange;
	shootRange = baseShootRange;
	name = baseName;
}

Healer::~Healer()
{
}

char Healer::getName()
{
	return name;
}

bool Healer::shoot(int x, int y)
{
	if (isInRange(x, y, shootRange)) {
		std::cout << "Case hors de portée. \n";
		return false;
	}
	if (pGrid->grid[y][x] != nullptr) {
		pGrid->grid[y][x]->heal(dmg);

	}
	else {
		std::cout << "pas de cible selectionee \n";
		return false;
	}
	return true;
}


