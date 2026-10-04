#pragma once
#include "Entity.h"

constexpr int entityNumber = 2;

class Player {
public:
	Player();

	Entity* entitys[entityNumber] = {};
};