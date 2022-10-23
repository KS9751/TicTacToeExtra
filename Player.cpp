#include "string.h"
#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(string symbol) {
	this->symbol = symbol;
	points = 0;
}

string Player::getSymbol() {
	return symbol;
}

void Player::getMove(int& r, int& c) {
	int row;
	int col;

	cout << "Where is your input row: \n";
	cin >> row;
	cout << "Where is your input colum: \n";
	cin >> col;

	r = row;
	c = col;	
}

void Player::awardPoint() {
	points++;
}

int Player::getPoints() {
	return points;
}



