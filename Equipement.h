#pragma once

class Equipement {
public :
	int value;
	enum boostType {
		Range,
		Move,
		Attack
	};

	boostType type;

	Equipement();
};