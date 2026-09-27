#include "Player.h"
#include "BaseTank.h"

Player::Player() {
	for (int i = 0; i < entityNumber; i++) {
		entitys[i] = new BaseTank();
	}
}