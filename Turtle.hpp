/*
 ** Author: David An
 ** Date: Jan 30 2018
 ** Description: This program contains the function prototypes for Turtle.cpp
 */

#ifndef Turtle_hpp
#define Turtle_hpp
#include "Animal.hpp"

class Turtle : public Animal {		// inherit behavior from the animal class
	
private:
	int quantity;
	
public:
	Turtle();
	Turtle(int);
	int getFoodCost(int);
	double calcPayoff(double);
};

#endif
