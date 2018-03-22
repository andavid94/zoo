/*
 ** Author: David An
 ** Date: Jan 30 2018
 ** Description: This program contains the function prototypes for Animal.cpp
 */

#ifndef Animal_hpp
#define Animal_hpp
#include <string>

class Animal {
	
protected:
	int age;
	double cost;
	int numOfBabies;
	double baseFoodCost;
	double payoff;

public:
	Animal();
	int getAge();
	void setAge(int);
	double getCost();
	int getNumOfBabies();
	double getBaseFoodCost();
	double getPayoff();
};

#endif
