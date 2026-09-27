#include "BaseTank.h"

int BaseTank::getValue() {
	return displayedValue;
}

BaseTank::BaseTank() {
	hp = baseHp;
	dmg = baseDmg;
	moveRange = baseMoveRange;
}