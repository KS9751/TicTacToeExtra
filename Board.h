#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Board {
private:
	string** board;
	int size = 0;
	int checkSpace = 0;

public:
	Board();
	Board(int size);
	void setBoard(int row, int col, string symbol);
	void display();
	bool isFull();
	bool isWinner();
	bool checkMove(int row, int col);
	void clear();
	~Board();
};