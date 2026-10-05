#include "BaseTank.h"

BaseTank::~BaseTank()
{
}

char BaseTank::getName() {
	return name;
}

BaseTank::BaseTank() : Entity() {
	hp = baseHp;
	dmg = baseDmg;
	moveRange = baseMoveRange;
	shootRange = baseShootRange;
	name = baseName;
}
