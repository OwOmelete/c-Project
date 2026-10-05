#include "Player.h"
#include "BaseTank.h"
#include "Bombardier.h"
#include "Healer.h"

Player::Player() {
	for (int i = 0; i < entityNumber; i++) {
		if (i == 0) {
			entitys[i] = new Bombardier();
		}
		else {
			entitys[i] = new Healer();
		}

	}
}