#pragma once
#include "Entity.h"

class Bombardier : public Entity {
private:
	int baseHp = 10;
	int baseDmg = 3;
	int baseMoveRange = 3;
	int baseShootRange = 3;
	int explosionRange = 2;
	char baseName = 'B';
public:

	bool shoot(int x, int y) override;

	Bombardier();


	~Bombardier() override;

	char getName() override;
};