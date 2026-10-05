#pragma once
#include "Entity.h"

class Healer : public Entity {
private:
	int baseHp = 10;
	int baseDmg = 20;
	int baseMoveRange = 10;
	int baseShootRange = 5;
	int explosionRange = 3;
	char baseName = 'H';

public:

	Healer();


	~Healer() override;

	char getName() override;

	bool shoot(int x, int y) override;
};