/*
 ** Author: David An
 ** Date: Jan 30 2018
 ** Description: This program contains the function prototypes for Penguin.cpp
 */

#ifndef Penguin_hpp
#define Penguin_hpp
#include "Animal.hpp"

class Penguin : public Animal {		// inherit behavior from the Animal class
	
private:
	int quantity;
	
public:
	Penguin();
	Penguin(int);
	int getFoodCost(int);
	double calcPayoff(double);
};

#endif
