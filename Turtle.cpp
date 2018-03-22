/*
 ** Author: David An
 ** Date: Jan 30 2018
 ** Description: This class represents a Turtle object and inherits behavior from
 ** 			 the Animal.cpp class
 */

#include "Turtle.hpp"

Turtle::Turtle() {}

/*
 ** Description: create a turtle object of age 'age'
 */
Turtle::Turtle(int age) {
	this -> age = age;
	this -> cost = 100.0;
	this -> numOfBabies = 10;
	this -> baseFoodCost = getFoodCost(10);
	this -> payoff = calcPayoff(cost);
}

int Turtle::getFoodCost(int base) {
	return base * .5;
}

/*
 ** Description: calculates the payoff based on the animal's cost
 */
double Turtle::calcPayoff(double cost) {
	return cost * .05;
}
