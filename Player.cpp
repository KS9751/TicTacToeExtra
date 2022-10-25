#include "string.h"
#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() {
	points = 0;
}

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

	r = row - 1;
	c = col - 1;	
}

void Player::awardPoint() {
	points++;
}

int Player::getPoints() {
	return points;
}

Player::~Player() {

}



