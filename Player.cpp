#include "Player.h"
#include "BaseTank.h"
#include "Bombardier.h"
#include "Healer.h"

Player::Player() {
	entitys[0] = new BaseTank();
	entitys[1] = new Bombardier();
	entitys[2] = new Healer();
}