#include <iostream>
#include "GameManager.h"
#include "Grid.h"

void GameManager::TurnBehaviour() {
	while (!isGameOver) {
		


	}
}

void GameManager::ChooseUnit() {
	bool isInputValid = false;

	while (!isInputValid) {

		std::cout << "Au tour de joueur " << currentPlayer << "\n";
		std::string s;
		s += "Choisissez une unité : ";
		for (int i = 0; i < entityNumber; i++)
		{
			if (players[currentPlayer].entitys[i] != nullptr) {
				s += i + ", ";
			}
		}
		std::cout << s << "\n";
		int n;
		std::cin >> n;

		if (players[currentPlayer].entitys[n] != nullptr) {
			isInputValid = true;
		}

	}
}

void GameManager::ChooseAction(int n) {
	bool isInputValid = false;
	int x;
	int y;
	while (!isInputValid) {
		std::cout << "Choisissez une action :\n";
		std::cout << "- m pour move l'unité sélectionnée \n";
		std::cout << "- a pour faire attaquer l'unité sélectionnée \n";
		std::cout << "- i pour obtenir les infos de l'unité sélectionnée \n";
		std::cout << "- r pour revenir en arrière \n";
		std::string input;
		std::cin >> input;
		if (input == "m") {
			bool canMove;
			while (!canMove) {
				ChooseTile(x, y);

				
			}

		}

	}
}

void GameManager::ChooseTile(int& x, int& y) {
	bool isInputValid;
	while (!isInputValid) {
		std::cout << "Entrez coordonee x :\n";
		std::cin >> x;
		std::cout << "Entrez coordonee y :\n";
		std::cin >> y;

		if (g.isCellValid(x, y)) {
			isInputValid = true;
		}
		else {
			std::cout << "Cellule invalide";
		}
	}
}

void GameManager::TurnBehaviourInit() {

	bool isValid = false;
	int currentIndex = 0;
	int x;
	int y;
	while (currentIndex < entityNumber || currentPlayer == 1) {
		while (!isValid) {
			std::cout << "Au tour de joueur " << currentPlayer << " de placer une unite\n";
			std::cout << "Entrez coordonee x :\n";
			std::cin >> x;
			std::cout << "Entrez coordonee y :\n";
			std::cin >> y;

			if (g.isCellValid(x, y)) {
				isValid = true;
				players[currentPlayer - 1].entitys[currentIndex]->init(g, x, y);
				g.displayGrid();
			}
			else {
				std::cout << "Placement invalide\n";
			}
		}
		isValid = false;
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
	



}