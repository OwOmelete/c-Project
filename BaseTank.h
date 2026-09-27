#pragma once
#include "Entity.h"

class BaseTank : public Entity {
private:
	int baseHp = 10;
	int baseDmg = 3;
	int baseMoveRange = 10;


	int displayedValue = 1;
public:

	BaseTank();

	int getValue() override;
};