#include <iostream>
#include <string.h>
#include "Player.h"
#include "Board.h"
using namespace std;
/*
enum Result {
	Continue,
	Win,
	Finish
};

string board[3][3] = {
	{" ", " ", " "},
	{" ", " ", " "},
	{" ", " ", " "}
};
int turn;
int choice = 1;
string ch;

void fillIn(string s) {
	int colum;
	int rows;
	cout << "Where is your input row: \n";
	cin >> rows;
	cout << "Where is your input colum: \n";
	cin >> colum;
	int compare;
	compare =  board[rows][colum].compare(" ");
	while (compare != 0) {
		cout << "It is not empty space. Try another one!\n";
		cout << "Where is you input colum: \n";
		cin >> colum;
		cout << "Where is yoour input rows: \n";
		cin >> rows;
		compare = board[colum][rows].compare(" ");
	}
	board[colum][rows] = s;
	cout << "Your input is set!\n";

}

int check() {
	int check1;
	int check2;
	int checkSpace;
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			checkSpace = board[i][j].compare(" ");
			if (checkSpace != 0) {
				count++;
			}
		}
	}

	// All the cells are filled. Game draw.
	if (count == 9) {
		return 2;
	}

	for (int i = 0; i < 3; i++) {
		check1 = board[i][0].compare(board[i][1]);
		check2 = board[i][1].compare(board[i][2]);
		if (board[i][0].compare(" ") != 0 && board[i][1].compare(" ") != 0 && board[i][2].compare(" ") != 0) {
			checkSpace = 0;
		}
		else {
			checkSpace = 1;
		}
		if (check1 == 0 &&  check2 == 0 && checkSpace == 0) {
			return 1;
		}
	}
	for (int j = 0; j < 3; j++) {
		check1 = board[0][j].compare(board[1][j]);
		check2 = board[1][j].compare(board[2][j]);
		if (board[0][j].compare(" ") != 0 && board[1][j].compare(" ") != 0 && board[2][j].compare(" ") != 0) {
			checkSpace = 0;
		}
		else {
			checkSpace = 1;
		}
		if (check1 == 0 && check2 == 0 && checkSpace == 0) {
			return 1;
		}
	}
	check1 = board[0][0].compare(board[1][1]);
	check2 = board[1][1].compare(board[2][2]);
	if (board[0][0].compare(" ") != 0 && board[1][1].compare(" ") != 0 && board[2][2].compare(" ") != 0) {
		checkSpace = 0;
	}
	else {
		checkSpace = 1;
	}
	if (check1 == 0 && check2 == 0 && checkSpace == 0) {
		return 1;
	}
	check1 = board[0][2].compare(board[1][1]);
	check2 = board[1][1].compare(board[2][0]);
	if (board[0][2].compare(" ") != 0 && board[1][1].compare(" ") != 0 && board[2][0].compare(" ") != 0) {
		checkSpace = 0;
	}
	else {
		checkSpace = 1;
	}
	if (check1 == 0 && check2 == 0 && checkSpace == 0) {
		return 1;
	}
	return 0;
}
*/
int main() {
	int choice = 1;
	Board* board = new Board();
	Player* p1 = new Player("X");
	Player* p2 = new Player("O");

	//Print out rule
	cout << "1. Tic-Tac-Toe is a two player game played with 3*3 grid.\n";
	cout << "2.In Tic-Tac-Toe, one player is assigned the letter 'X', and the other player is assigned the letter 'O'.\n";
	cout << "3.Only one player place letter in the grid each turn. Odd number x player place letter and even turn O player place letter.\n";
	cout << "4.At the end of each turn, if an entire row, column, or diagonal of the grid is occupied only by 'X' symbols or 'O' symbols, the player assigned that letter wins the game, and the game ends.\n";

	while (choice != 0) {
		board->clear();
	
		//game start
		int row;
		int col;
		int turn = 1;

		while (true) {
			if (turn % 2 == 1) {
				if (!board->isFull()) {
					board->display();
					cout << "X turn: \n";
					
					p1->getMove(row, col);
					while (!board->checkMove(row, col)) {
						cout << "You cannot place your letter here.\n";
						p1->getMove(row, col);
					}
					board->setBoard(row, col, "X");
					
				}
				bool hasWinner = board->isWinner();

				if (hasWinner) {
					cout << "Player X win!\n";
					p1->awardPoint();
					cout << "Score of player x: " << p1->getPoints() << "\n";
					cout << "Score of player o: " << p2->getPoints() << "\n";
					break;
				}

				if (board->isFull()) {
					cout << "Draw\n";
					cout << "Score of player x: " << p1->getPoints() << "\n";
					cout << "Score of player o: " << p2->getPoints() << "\n";
					break;
				}

				turn++;

			}
			else {
				if (!board->isFull()) {
					board->display();
					cout << "O turn: \n";

					p2->getMove(row, col);
					while (!board->checkMove(row, col)) {
						cout << "You cannot place your letter here.\n";
						p2->getMove(row, col);
					}
					board->setBoard(row, col, "O");

				}
				bool hasWinner = board->isWinner();

				if (hasWinner) {
					cout << "Player O win!\n";
					p2->awardPoint();
					cout << "Score of player x: " << p1->getPoints() << "\n";
					cout << "Score of player o: " << p2->getPoints() << "\n";
					break;
				}

				if (board->isFull()) {
					cout << "Draw\n";
					cout << "Score of player x: " << p1->getPoints() << "\n";
					cout << "Score of player o: " << p2->getPoints() << "\n";
					break;
				}

				turn++;

			}
		}

		board->display();

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
	return 0;
}