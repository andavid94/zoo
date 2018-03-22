/*
 ** Author: David An
 ** Date: Jan 30 2018
 ** Description: This class represents a Tiger object and inherits behavior from
 ** 			 the Animal.cpp class.
 */

#include "Tiger.hpp"

Tiger::Tiger() {}

/*
 ** Description: creates a tiger object of age 'age'
 */
Tiger::Tiger(int age) {
	this -> age = age;
	this -> cost = 10000.0;
	this -> numOfBabies = 1;
	this -> baseFoodCost = getFoodCost(10);
	this -> payoff = calcPayoff(cost);
}

int Tiger::getFoodCost(int base) {
	return base * 5;
}

/*
 ** Description: calculates the payoff based on the animal's cost
 */
double Tiger::calcPayoff(double cost) {
	return cost * .2;
}






