#include "string.h"
#include <iostream>
#include "Board.h"
using namespace std;

Board::Board() {	
}



void Board::display() {
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j].compare(" ") == 0 ? cout << "_" : cout << board[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

bool Board::isFull() {
	checkSpace = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			checkSpace = board[i][j].compare(" ");
			if (checkSpace == 0) {
				return false;
			}
		}
	}

	return true;
}

bool Board::isWinner() {
	int check1;
	int check2;
	int checkSpace;

	//Check for a horizontal line
	for (int i = 0; i < 3; i++) {
		check1 = board[i][0].compare(board[i][1]);
		check2 = board[i][1].compare(board[i][2]);
		if (board[i][0].compare(" ") != 0 && board[i][1].compare(" ") != 0 && board[i][2].compare(" ") != 0) {
			checkSpace = 0;
		}
		else {
			checkSpace = 1;
		}
		if (check1 == 0 && check2 == 0 && checkSpace == 0) {
			return true;
		}
	}

	//Check for a vertical line
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
			return true;
		}
	}

	//Check for descending digonal
	check1 = board[0][0].compare(board[1][1]);
	check2 = board[1][1].compare(board[2][2]);
	if (board[0][0].compare(" ") != 0 && board[1][1].compare(" ") != 0 && board[2][2].compare(" ") != 0) {
		checkSpace = 0;
	}
	else {
		checkSpace = 1;
	}
	if (check1 == 0 && check2 == 0 && checkSpace == 0) {
		return true;
	}

	//check for asending digonal
	check1 = board[0][2].compare(board[1][1]);
	check2 = board[1][1].compare(board[2][0]);
	if (board[0][2].compare(" ") != 0 && board[1][1].compare(" ") != 0 && board[2][0].compare(" ") != 0) {
		checkSpace = 0;
	}
	else {
		checkSpace = 1;
	}
	if (check1 == 0 && check2 == 0 && checkSpace == 0) {
		return true;
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
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = " ";
		}
	}
}

void Board::setBoard(int row, int col, string symbol) {
	board[row][col] = symbol;
}
