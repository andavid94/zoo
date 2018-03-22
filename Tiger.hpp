/*
 ** Author: David An
 ** Date: Jan 30 2018
 ** Description: This program contains all function prototypes for the Tiger.cpp class
 */

#ifndef Tiger_hpp
#define Tiger_hpp
#include "Animal.hpp"

class Tiger : public Animal {  // inherit behavior from the Animal class

private:
	int quantity;
	
public:
	Tiger();
	Tiger(int);
	int getFoodCost(int);
	double calcPayoff(double);
};

#endif
