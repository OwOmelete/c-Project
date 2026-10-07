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
	int ChooseUnit(int player);
	char ChooseAction();
	char ChooseActionHealing();
	void ChooseTile(int& x, int& y);
	bool ActionBehaviour(Entity* selectedUnit);
	int WinCondition();
	bool ManageWin();
	void DeathDetection();
	void LootEquipement(int n, int player);

	
	
public:
	void Init();

};