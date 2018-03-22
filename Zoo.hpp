/*
 ** Description: this program contains the function prototypes for the Zoo.cpp class
 */

#ifndef Zoo_hpp
#define Zoo_hpp

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <iostream>

class Zoo {
private:
	int funds;
	int turns;
	int payout;
	int dailyProfit;
	int tigerArraySize;
	int penguinArraySize;
	int turtleArraySize;
	Tiger *tigerArray;
	Penguin *penguinArray;
	Turtle *turtleArray;
	int tigers;
	int penguins;
	int turtles;
public:
	Zoo();
	void clearArrays();
	void endOfDay();
	void setup();
	void simulateDay();
	void randomEvent();
	void setFunds(int);
	int playAgain();
	int getFunds();
	int getTigers();
	int getPenguins();
	int getTurtles();
};


#endif
