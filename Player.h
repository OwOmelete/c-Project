#pragma once
#include "Entity.h"

constexpr int entityNumber = 3;

class Player {
public:
	Player();

	Entity* entitys[entityNumber] = {};
};