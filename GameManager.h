#pragma once
#include "Player.h"

class GameManager {

private:

	Grid g;

	bool isGameOver = false;

	int currentPlayer = 1;
	Player players[2];

	void TurnBehaviour();
	void TurnBehaviourInit();
	void ChooseUnit();
	void ChooseAction(int n);
	void ChooseTile(int& x, int& y);
	
public:
	void Init();

};