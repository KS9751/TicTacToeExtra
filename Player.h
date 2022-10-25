#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Player {
private:
	string symbol;
	int points;
	
public:
	Player();
	Player(string symbol);
	string getSymbol();
	void getMove(int& r,int& c);
	void awardPoint();
	int getPoints();
	~Player();
};