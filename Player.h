#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Player {
private:
	string symbol;
	int points;
	
public:
	Player(string sybol);
	string getSymbol();
	void getMove(int& r,int& c);
	void awardPoint();
	int getPoints();
};