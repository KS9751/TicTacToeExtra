#include "string.h"
#include <iostream>
#include "Board.h"
using namespace std;

Board::Board(int size) {
	this->size = size;
	board = new string*[size];

	for (int i = 0; i < size; i++) {
		board[i] = new string[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = " ";
		}
	}
}


void Board::display() {
	cout << "\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j].compare(" ") == 0 ? cout << "_" : cout << board[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

bool Board::isFull() {
	checkSpace = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			checkSpace = board[i][j].compare(" ");
			if (checkSpace == 0) {
				return false;
			}
		}
	}

	return true;
}

bool Board::isWinner() {	

	//Check for a horizontal line
	for (int row = 0; row < size; row++) {
		if (board[row][0].compare(" ") == 0) {
			continue;
		}

		int col = 1;
		for (; col < size; col++) {
			if (board[row][col].compare(board[row][0]) != 0) {
				break;
			}
		}

		if (col == size) {
			return true;
		}		
	}

	//Check for a vertical line
	for (int col = 0; col < size; col++) {
		if (board[0][col].compare(" ") == 0) {
			continue;
		}

		int row = 1;
		for (; row < size; row++) {
			if (board[row][col].compare(board[0][col]) != 0) {
				break;
			}
		}

		if (row == size) {
			return true;
		}
	}

	//Check for descending digonal
	if (board[0][0].compare(" ") != 0) {
		int i;
		for (i = 0; i < size - 1; i++) {
			if (board[i][i].compare(board[i + 1][i + 1]) != 0) {
				break;
			}
		}

		if (i == size - 1) {
			return true;
		}
	}

	//check for asending digonal
	if (board[size - 1][0].compare(" ") != 0) {
		int row, col;
		for (row = size - 1, col = 0 ; row > 0; row--, col++) {
			if (board[row][col].compare(board[row - 1][col + 1]) != 0) {
				break;
			}
		}

		if (row == 0) {
			return true;
		}
	}

	return false;
}
	

bool Board::checkMove(int row, int col) {
	int compare = board[row][col].compare(" ");
	if (compare == 0) {
		return true;
	}
	return false;
}

void Board::clear() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = " ";
		}
	}
}

void Board::setBoard(int row, int col, string symbol) {
	board[row][col] = symbol;
}

Board::~Board() {
	for (int i = 0; i < size; i++) {
		delete board[i];
	}
}
