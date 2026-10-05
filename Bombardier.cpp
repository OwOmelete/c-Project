#include "Bombardier.h"

bool Bombardier::shoot(int x, int y)
{
	if (isInRange(x, y, shootRange)) {
		std::cout << "Case hors de portée. \n";
		return false;
	}


	// Attaque de zone 
	for (int i = -explosionRange; i <= explosionRange; i++) {

		int L = explosionRange - abs(i);

		for (int j = -L; j <= L; j++) {
			int xCoord = x + i;
			int yCoord = y + j;

			if (pGrid->isCellInGrid(xCoord, yCoord)) {

				if (pGrid->grid[yCoord][xCoord] != nullptr) {
					std::cout << "Touche! \n";

					pGrid->grid[yCoord][xCoord]->takeDamage(dmg);

				}
				else {
					std::cout << xCoord << ", " << yCoord << "\n";
				}
			}
		}
	}
	return true;
}

Bombardier::Bombardier() : Entity()
{
	hp = baseHp;
	dmg = baseDmg;
	moveRange = baseMoveRange;
	shootRange = baseShootRange;
	name = baseName;
}

Bombardier::~Bombardier()
{
}

char Bombardier::getName()
{
	return name;
}


