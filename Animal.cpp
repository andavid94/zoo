/*
 ** Author: David An
 ** Date: Jan 30 2018
 ** Description: This class contains the basic behavior of an animal, including
 ** 			 the age, cost, numbers of babies, base food costs, and payoffs.
 */

#include "Animal.hpp"
#include <string>

Animal::Animal() {}

int Animal::getAge() {
	return age;
}

void Animal::setAge(int newAge) {
	age = newAge;
}

double Animal::getCost() {
	return cost;
}

int Animal::getNumOfBabies() {
	return numOfBabies;
}

double Animal::getBaseFoodCost() {
	return baseFoodCost;
}

double Animal::getPayoff() {
	return payoff;
}


