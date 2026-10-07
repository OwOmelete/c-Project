#include <iostream>
#include "conio.h"
#include "GameManager.h"
#include "Grid.h"
#include "Equipement.h"


//Boucle de jeu principale
void GameManager::TurnBehaviour() {

	bool isActionDone = false;


	while (!isGameOver) {
		std::cout << "Au tour de joueur " << currentPlayer << "\n";

		isActionDone = false;
		while (!isActionDone) {
			Entity* selectedUnit = players[currentPlayer - 1].entitys[ChooseUnit(currentPlayer)];
			isActionDone = ActionBehaviour(selectedUnit);
		}

		g.displayGrid();
		if (currentPlayer == 2) {
			currentPlayer = 1;
		}
		else {
			currentPlayer = 2;
		}

		DeathDetection();

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

	char action;


	//Pas très propre, dans l'idéal j'aurais fait un système d'action qui stockent input, description et fonction associée qui auraient pu être associés a certaines unités pour quelque chose de plus évolutif

	if (selectedUnit->getName() == 'H') {
		action = ChooseActionHealing();
	}
	else {
		action = ChooseAction();
	}


	switch (action) {
	case 'r':
		return false;
	case 'm':
		ChooseTile(x, y);
		return selectedUnit->move(x, y);
	case 'a': {
		ChooseTile(x, y);
		return selectedUnit->shoot(x, y);
	}
	case 'h': {
		ChooseTile(x, y);
		return selectedUnit->shoot(x, y);
	}
	}
}

void GameManager::DeathDetection() {
	int lootPlayer1 = 0;
	int lootPlayer2 = 0;

	for (int i = 0; i < entityNumber; i++)
	{
		if (players[1].entitys[i] != nullptr) {
			if (!players[1].entitys[i]->isAlive()) {
				delete players[1].entitys[i];
				players[1].entitys[i] = nullptr;
				lootPlayer1++;
			}
		}
	}
	for (int i = 0; i < entityNumber; i++)
	{
		if (players[0].entitys[i] != nullptr) {
			if (!players[0].entitys[i]->isAlive()) {
				delete players[0].entitys[i];
				players[0].entitys[i] = nullptr;
				lootPlayer2++;
			}
		}
	}

	if (lootPlayer1 > 0) {
		LootEquipement(lootPlayer1, 1);
	}
	if (lootPlayer2 > 0) {
		LootEquipement(lootPlayer2, 2);
	}

}

void GameManager::LootEquipement(int n, int player)
{
	for (int i = 0; i < n; i++) {
		Equipement equipement = Equipement();

		std::cout << "Joueur " << player << ".";

		switch (equipement.type)
		{
		case Equipement::Attack:
			std::cout << " Vous avez trouve un equipement qui augmente l'attaque de " << equipement.value << ".\n";

			break;
		case Equipement::Move:
			std::cout << " Vous avez trouve un equipement qui augmente les deplacements de " << equipement.value << ".\n";
			break;
		case Equipement::Range:
			std::cout << " Vous avez trouve un equipement qui augmente la portee de " << equipement.value << ".\n";
			break;
		}
		std::cout << "Choisissez l'unite sur laquelle vous voulez installer cet equipement. \n";

		Entity* selectedUnit = players[player - 1].entitys[ChooseUnit(player)];

		selectedUnit->installEquipement(&equipement);

		std::cout << "Equipement installe. \n";

	}
}



int GameManager::ChooseUnit(int player) {
	bool isInputValid = false;
	int input;

	while (!isInputValid) {
		std::string s;
		std::cout << "Choisissez une unite : \n";
		for (int i = 0; i < entityNumber; i++)
		{
			if (players[player - 1].entitys[i] != nullptr) {
				std::cout << players[player - 1].entitys[i]->getName() << " - " << i << "\n";
			}
		}
		std::cout << "\n";
		std::cin >> input;

		if (players[player - 1].entitys[input] != nullptr) {
			isInputValid = true;
		}
	}
	return input;
}

char GameManager::ChooseAction() {
	bool isInputValid = false;
	char actions[3]{ 'm','a','r' };
	while (!isInputValid) {
		std::cout << "Choisissez une action :\n";
		std::cout << "- m pour move l'unite selectionnée \n";
		std::cout << "- a pour faire attaquer l'unite selectionnee \n";
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

char GameManager::ChooseActionHealing() {
	bool isInputValid = false;
	char actions[3]{ 'm','h','r' };
	while (!isInputValid) {
		std::cout << "Choisissez une action :\n";
		std::cout << "- m pour move l'unite selectionnee \n";
		std::cout << "- h pour soigner l'unite selectionnee \n";
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

			if (g.isCellInGrid(x, y) && !g.isCellOccupied(x, y)) {
				isValid = true;
				players[currentPlayer - 1].entitys[currentIndex]->init(&g, x, y, currentPlayer);
				g.displayGrid();
			}
			else {
				std::cout << "Placement invalide\n";
			}
		}
		isValid = false;
		if (currentIndex == entityNumber - 1 && currentPlayer == 2) {
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