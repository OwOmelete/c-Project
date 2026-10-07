#pragma once
#include "Entity.h"

class Healer : public Entity {
private:
	int baseHp = 8;
	int baseDmg = 3;
	int baseMoveRange = 4;
	int baseShootRange = 5;
	char baseName = 'H';

public:

	Healer();


	~Healer() override;

	char getName() override;

	bool shoot(int x, int y) override;
};