#include "BaseTank.h"

BaseTank::~BaseTank()
{
}

int BaseTank::getValue() {
	return displayedValue;
}

BaseTank::BaseTank() : Entity() {
	hp = baseHp;
	dmg = baseDmg;
	moveRange = baseMoveRange;
	shootRange = baseShootRange;
}
