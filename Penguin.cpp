/*
 ** Author: David An
 ** Date: Jan 30 2018
 ** Description: This class represents a Penguin object and inherits behavior from
 ** 			 the Animal.cpp class
 */

#include "Penguin.hpp"

Penguin::Penguin() {}

/*
 ** Description: creates a penguin object of age 'age'
 */
Penguin::Penguin(int age) {
	this -> age = age;
	this -> cost = 1000.0;
	this -> numOfBabies = 5;
	this -> baseFoodCost = getFoodCost(10);
	this -> payoff = calcPayoff(cost);
}

int Penguin::getFoodCost(int base) {
	return base;
}

/*
 ** Description: calculates the payoff based on the animal's cost
 */
double Penguin::calcPayoff(double cost) {
	return cost * .1;
}
