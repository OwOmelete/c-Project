#pragma once
#include "Entity.h"

class Bombardier : public Entity {
private:
	int baseHp = 10;
	int baseDmg = 20;
	int baseMoveRange = 10;
	int baseShootRange = 5;
	int explosionRange = 3;
	char baseName = 'B';
public:

	bool shoot(int x, int y) override;

	Bombardier();


	~Bombardier() override;

	char getName() override;
};