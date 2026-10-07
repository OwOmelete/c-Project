#pragma once
#include "Entity.h"

class BaseTank : public Entity {
private:
	int baseHp = 10;
	int baseDmg = 4;
	int baseMoveRange = 3;
	int baseShootRange = 5;


	char baseName = 'T';
public:

	BaseTank();

	
	~BaseTank() override;

	char getName() override;
};