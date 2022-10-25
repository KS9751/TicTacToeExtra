#include <iostream>
#include <string.h>
#include "Player.h"
#include "Board.h"

using namespace std;

int main() {
	
	//Print out rule
	cout << "1. Tic-Tac-Toe is a multiple players game played with N*N grid.\n";
	cout << "2. In Tic-Tac-Toe, one player is assigned a letter such as 'X', and the other player is assigned another letter such as 'O'.\n";
	cout << "3. Only one player place letter in the grid each turn. \n";
	cout << "4. At the end of each turn, if an entire row, column, or diagonal of the grid is occupied only by 'X' symbols or 'O' symbols, the player assigned that letter wins the game, and the game ends.\n";

	cout << "\n\n";

	int boardSize = 0;
	cout << "Please specify the size of the board.\n";
	cin >> boardSize;

	int playerCount = 0;
	cout << "Please specify the number of players \n";
	cin >> playerCount;

	Player* players = new Player[playerCount];

	string playerSymbol;
	for (int i = 0; i < playerCount; i++) {
		cout << "Player " << i + 1 << ": What symbol do you want to use? \n";
		cin >> playerSymbol;
		players[i] = Player(playerSymbol);
	}

	int choice = 1;
	Board* board = new Board(boardSize);
	

	while (choice != 0) {
		board->clear();
	
		//game start
		int row;
		int col;

		bool gameOver = false;

		while (true) {
			for(int i = 0; i < playerCount; i++) {
				if (!board->isFull()) {
					board->display();
					cout << "Player " << i + 1 << ": It's your turn. " << "Your symbol is " << players[i].getSymbol() << "\n";
					
					players[i].getMove(row, col);
					while (!board->checkMove(row, col)) {
						cout << "You cannot place your letter here.\n";
						players[i].getMove(row, col);
					}
					board->setBoard(row, col, players[i].getSymbol());
					
				}

				bool hasWinner = board->isWinner();

				if (hasWinner) {
					cout << "\nPlayer " << i + 1 << " won!\n";
					board->display();
					players[i].awardPoint();
					for (int i = 0; i < playerCount; i++) {
						cout << "Score of player " << i + 1 << " is: " << players[i].getPoints() << "\n";
					}
					gameOver = true;
					break;
				}

				if (board->isFull()) {
					cout << "\nDraw\n";
					board->display();
					for (int i = 0; i < playerCount; i++) {
						cout << "Score of player " << i + 1 << " is: " << players[i].getPoints() << "\n";
					}
					gameOver = true;
					break;
				}
			}

			if (gameOver) {
				break;
			}
		}

		cout << "Do you want another game? (Enter 0 to quit and 1 to continue)\n";
		cin >> choice;
		if (choice != 0) {
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
		}
	}

	cout << "Hope you like this game. See you next time!\n";

	delete board;
	delete players;

	return 0;
}