#pragma once
#include "Entity.h"

class BaseTank : public Entity {
private:
	int baseHp = 10;
	int baseDmg = 20;
	int baseMoveRange = 10;
	int baseShootRange = 5;


	int displayedValue = 1;
public:

	BaseTank();

	
	~BaseTank() override;

	int getValue() override;
};