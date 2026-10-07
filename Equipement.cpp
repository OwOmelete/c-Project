#include "Equipement.h"
#include <iostream>

Equipement::Equipement()
{
	type = boostType(rand() % 3);

	switch (type){
	case Attack:
		value = rand() % 4;
		break;
	case Move:
		value = rand() % 2;
		break;
	case Range:
		value = rand() % 3;
		break;
	}
}
