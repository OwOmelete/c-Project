#include <iostream>
#include "conio.h"
#include "GameManager.h"
#include "Grid.h"


//Boucle de jeu principale
void GameManager::TurnBehaviour() {

	bool isActionDone = false;


	while (!isGameOver) {
		std::cout << "Au tour de joueur " << currentPlayer << "\n";
		Entity* selectedUnit = players[currentPlayer-1].entitys[ChooseUnit()];

		isActionDone = false;
		while (!isActionDone) {
			isActionDone = ActionBehaviour(selectedUnit);
		}

		g.displayGrid();
		if (currentPlayer == 2) {
			currentPlayer = 1;
		}
		else {
			currentPlayer = 2;
		}

		isGameOver = ManageWin();

	}
	std::cout << "Partie terminee ! \n";
}

int GameManager::WinCondition()
{
	bool Player1Alive = false;
	bool Player2Alive = false;

	for (int i = 0; i < entityNumber; i++)
	{
		if (players[0].entitys[i] != nullptr) {
			Player1Alive = true;
		}
	}
	for (int i = 0; i < entityNumber; i++)
	{
		if (players[1].entitys[i] != nullptr) {
			Player2Alive = true;
		}
	}
	if (!Player1Alive && !Player2Alive) return 3;
	else if (!Player1Alive) return 1;
	else if (!Player2Alive) return 2;
	else return 0;
	
}

bool GameManager::ManageWin()
{
	int w = WinCondition();
	switch (w) {
	case '0':
		std::cout << "Les deux joueurs sont encore en vie \n";

		return false;
		
	case '1':
		std::cout << "Joueur 1 a gagne ! \n";

		return true;

	case '2':
		std::cout << "Joueur 2 a gagne ! \n";
		return true;

	case '3':
		std::cout << "Match nul ! \n";
		return true;
	}
}

bool GameManager::ActionBehaviour(Entity* selectedUnit) {
	int x;
	int y;

	char action = ChooseAction();

	switch (action) {
	case 'r':
		return false;
	case 'm':
		ChooseTile(x, y);
		return selectedUnit->move(x, y);
	case 'a': {

		//result = "code" de retour de shoot : -2 = case invalide, -1 = tir sur une case vide, le reste sont les pvs restants de l'unité touchée, dans le cas ou on retourne 0, on élimine la cible.

		ChooseTile(x, y);
		int result = selectedUnit->shoot(x, y);
		if (result == -2) {
			return false;
		}
		else if (result == 0) {
			ManageDeath(x, y);
		}
		return true;
	}
	case 'i':
		return false;
	}
}

void GameManager::ManageDeath(int x, int y) {
	int owner = g.grid[y][x]->playerOwner;

	for (int i = 0; i < entityNumber; i++) {
		if (g.grid[y][x] == players[owner - 1].entitys[i]) {
			delete g.grid[y][x];
			players[owner - 1].entitys[i] = nullptr;
		}
	}
}




int GameManager::ChooseUnit() {
	bool isInputValid = false;
	int input;

	while (!isInputValid) {
		std::string s;
		std::cout << "Choisissez une unite : ";
		for (int i = 0; i < entityNumber; i++)
		{
			if (players[currentPlayer-1].entitys[i] != nullptr) {
				std::cout << i << ",";

			}
		}
		std::cout << "\n";
		std::cin >> input;

		if (players[currentPlayer-1].entitys[input] != nullptr) {
			isInputValid = true;
		}
	}
	return input;
}

char GameManager::ChooseAction() {
	bool isInputValid = false;
	char actions[4]{ 'm','a','i','r' };
	while (!isInputValid) {
		std::cout << "Choisissez une action :\n";
		std::cout << "- m pour move l'unite selectionnée \n";
		std::cout << "- a pour faire attaquer l'unite selectionnee \n";
		std::cout << "- i pour obtenir les infos de l'unite selectionnee \n";
		std::cout << "- r pour revenir en arriere \n";
		char input = _getch();
		
		for (char c : actions) {
			if (input == c) {
				return c;
			}
		}

		std::cout << "Action invalide. \n";

	}
}

void GameManager::ChooseTile(int& x, int& y) {
	bool isInputValid = false;
	while (!isInputValid) {
		std::cout << "Entrez coordonee x :\n";
		std::cin >> x;
		std::cout << "Entrez coordonee y :\n";
		std::cin >> y;

		if (g.isCellInGrid(x, y)) {
			return;
		}
		else {
			std::cout << "Case sélectionnée en dehors de la grille. ";
		}
	}
}

//Tours de préparation, ou les joueurs placent leurs unités

void GameManager::TurnBehaviourInit() {

	bool isValid = false;
	int currentIndex = 0;
	int x;
	int y;
	while (true) {
		while (!isValid) {
			std::cout << "Au tour de joueur " << currentPlayer << " de placer une unite\n";
			std::cout << "Entrez coordonee x :\n";
			std::cin >> x;
			std::cout << "Entrez coordonee y :\n";
			std::cin >> y;

			if (g.isCellInGrid(x, y) && !g.isCellOccupied(x,y)) {
				isValid = true;
				players[currentPlayer - 1].entitys[currentIndex]->init(&g, x, y, currentPlayer);
				g.displayGrid();
			}
			else {
				std::cout << "Placement invalide\n";
			}
		}
		isValid = false;
		if (currentIndex == entityNumber-1 && currentPlayer == 2) {
			currentPlayer = 1;
			return;
		}
		if (currentPlayer == 2) {
			currentPlayer = 1;
			currentIndex++;
		}
		else {
			currentPlayer++;
		}
		
	}
}

void GameManager::Init() {
	g = Grid();
	g.displayGrid();
	players[0] = Player();
	players[1] = Player();

	TurnBehaviourInit();
	TurnBehaviour();
}