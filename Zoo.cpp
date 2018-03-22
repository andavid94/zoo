/*
 ** Description: this class contains the methods that are used to simulate the Zoo
 ** 			 program and keeps track of the total animals and current funds
 */

#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Zoo::Zoo() {}

/*
 ** Description: this function sets up the zoo environment with animals
 ** 			 based on the user's input
 */
void Zoo::setup() {
	
	// initialize dynamic arrays for animals
	tigerArraySize = 10;
	penguinArraySize = 10;
	turtleArraySize = 10;
	tigerArray = new Tiger[tigerArraySize];
	penguinArray = new Penguin[penguinArraySize];
	turtleArray = new Turtle[turtleArraySize];
	
	setFunds(100000);
	
	std::cout << "All user input will be rounded down to the nearest integer.\n";
	std::cout << "You will start off with $100,000 in the bank.\n";
	std::cout << "Please purchase 1 or 2 Tigers, Penguins, and Turtles\n";
	
	std::cout << "How many Tigers would you like to purchase? (1 or 2)\n";
	tigers = inputValidation(1, 2);		// get the desired number of tigers to purchase
	for (int i = 0; i < tigers; i++) {	// for each desired tiger
		Tiger tiger(1);					// create a tiger object of age 1
		tigerArray[i] = tiger;			// add the tiger to the tiger array
		funds -= tiger.getCost();		// subtract cost of tiger from the total funds
	}
	
	std::cout << "How many Penguins would you like to purchase? (1 or 2)\n";
	penguins = inputValidation(1, 2);
	for (int i = 0; i < penguins; i++) {
		Penguin penguin(1);
		penguinArray[i] = penguin;
		funds -= penguin.getCost();
	}
	
	std::cout << "How many Turtles would you like to purchase? (1 or 2)\n";
	turtles = inputValidation(1, 2);
	for (int i = 0; i < turtles; i++) {
		Turtle turtle(1);
		turtleArray[i] = turtle;
		funds -= turtle.getCost();
	}
}

/*
 ** Description: this function increments the age of each animal in the zoo and
 ** 			 subtracts the respective food costs
 */
void Zoo::simulateDay() {
	for (int i = 0; i < tigers; i++) {
		int currentAge = tigerArray[i].getAge();	// get the age of the tiger
		tigerArray[i].setAge(currentAge + 1);		// increment age
		funds -= tigerArray[i].getBaseFoodCost();	// subtract food cost from funds
	}
	
	for (int i = 0; i < penguins; i++) {
		int currentAge = penguinArray[i].getAge();
		penguinArray[i].setAge(currentAge + 1);
		funds -= penguinArray[i].getBaseFoodCost();
	}
	
	for (int i = 0; i < turtles; i++) {
		int currentAge = turtleArray[i].getAge();
		turtleArray[i].setAge(currentAge + 1);
		funds -= turtleArray[i].getBaseFoodCost();
	}
}

/*
 ** Description: this function executes a random event in the zoo
 */
void Zoo::randomEvent() {
	int decider = rand() % 4 + 1;		   // generate a random number between 1 and 4
	if (decider == 1) {					   // an animals dies
		int animalToDie = rand() % 3 + 1;  // randomly choose an animal to die
		if (animalToDie == 1) {
			// remove a tiger from the tigerArray
			if (tigers >= 1) {
				tigerArray[tigers - 1] = 0;
				tigers--;				   // decrement number of tigers in the zoo
				std::cout << "A tiger has died!\n";
			} else {
				std::cout << "There are no tigers in the Zoo to die.\n";
			}
		} else if (animalToDie == 2) {
			// remove a penguin from penguinArray
			if (penguins >= 1) {
				penguinArray[penguins - 1] = 0;
				penguins--;
				std::cout << "A penguin has died!\n";
			} else {
				std::cout << "There are no penguins in the Zoo to die.\n";
			}
		} else if (animalToDie == 3) {
			// remove a turtle from turtleArray
			if (turtles >= 1) {
				turtleArray[turtles - 1] = 0;
				turtles--;
				std::cout << "A turtle has died!\n";
			} else {
				std::cout << "There are no turtles in the Zoo to die.\n";
			}
		}
	} else if (decider == 2) {				// user gets a bonus for each tiger
		int bonus = rand() % 251 + 250;		// randomly generate bonus
		dailyProfit = (bonus * tigers);		// add bonus to the daily profit
		std::cout << "Your tigers have resulted in a bonus of $" << dailyProfit << std::endl;
	} else if (decider == 3) {				// an animal will be born
		int animalBorn = rand() % 3 + 1;	// randomly choose an animal to be born
		bool oldEnough = false;
		if (animalBorn == 1) {
			for (int i = 0; i < tigers; i++) {
				if (tigerArray[i].getAge() >= 3) {
					oldEnough = true;		// there is a tiger old enough to have babies
				}
			}
			if (oldEnough == true) {
				Tiger babyTiger(0);
				tigers++;
				// create a new, larger array if necessary
				if (tigers > tigerArraySize) {
					tigerArraySize *= 2;
					Tiger *tigerTempArray = new Tiger[tigerArraySize];
					// copy each tiger into the new array
					for (int i = 0; i < tigers - 1; i++) {
						tigerTempArray[i] = tigerArray[i];
					}
					delete []tigerArray;
					tigerArray = tigerTempArray;
				}
				std::cout << "A tiger has been born!\n";
				tigerArray[tigers] = babyTiger;
			} else {
				std::cout << "There are no Tigers old enough to have babies!\n";
			}
		} else if (animalBorn == 2) {
			for (int i = 0; i < penguins; i++) {
				if (penguinArray[i].getAge() >= 3) {
					oldEnough = true;
				}
			}
			if (oldEnough == true) {
				Penguin babyPenguin(0);
				penguins += babyPenguin.getNumOfBabies();
				if (penguins > penguinArraySize) {
					penguinArraySize *= 2;
					Penguin *penguinTempArray = new Penguin[penguinArraySize];
					for (int i = 0; i < penguins - 1; i++) {
						penguinTempArray[i] = penguinArray[i];
					}
					delete []penguinArray;
					penguinArray = penguinTempArray;
				}
				std::cout << "5 penguins have been born!\n";
				for (int i = babyPenguin.getNumOfBabies(); i > 0; i--) {
					penguinArray[penguins - i] = babyPenguin;
				}
			} else {
				std::cout << "There are no penguins old enough to have babies!\n";
			}
		} else if (animalBorn == 3) {
			for (int i = 0; i < turtles; i++) {
				if (turtleArray[i].getAge() >= 3) {
					oldEnough = true;
				}
			}
			if (oldEnough == true) {
				Turtle babyTurtle(0);
				turtles += babyTurtle.getNumOfBabies();
				if (turtles > turtleArraySize) {
					turtleArraySize *= 2;
					Turtle *turtleTempArray = new Turtle[turtleArraySize];
					for (int i = 0; i < turtles - 1; i++) {
						turtleTempArray[i] = turtleArray[i];
					}
					delete []turtleArray;
					turtleArray = turtleTempArray;
				}
				std::cout << "10 turtles have been born!\n";
				for (int i = babyTurtle.getNumOfBabies(); i > 0; i--) {
					turtleArray[turtles - i] = babyTurtle;
				}
			} else {
				std::cout << "There are no turtles old enough to have babies!\n";
			}
		}
	} else if (decider == 4) {			// nothing happens
		std::cout << "No random event occured today!\n";
	}
}

/*
 ** Description: this function calculates the daily profit and presents it to the user.
 ** 			 It also asks the user if they want to buy another adult animal.
 */
void Zoo::endOfDay() {
	Tiger tiger(0);
	int tigerProfit = tigers * tiger.getPayoff();  // add tiger's payoff to the daily profit
	Penguin penguin(0);
	int penguinProfit = penguins * penguin.getPayoff();
	Turtle turtle(0);
	int turtleProfit = turtles * turtle.getPayoff();
	dailyProfit = dailyProfit + tigerProfit + penguinProfit + turtleProfit;
	
	std::cout << "The profit for the day is $" << dailyProfit << std::endl;
	funds += dailyProfit;
	dailyProfit = 0;  	// reset daily profit to zero for the next day
	std::cout << "Your total funds are $" << funds << std::endl;
	
	std::cout << "Would you like to buy an adult animal? \n1. Yes \n2. No\n";
	int response = inputValidation(1, 2);
	if (response == 1) {
		std::cout << "Enter 1 to buy a Tiger, 2 to buy a Penguin, or 3 to buy a Turtle\n";
		int animalToBuy = inputValidation(1, 3);
		if (animalToBuy == 1) {
			Tiger adultTiger(3);	// create a new tiger object of age 3
			tigers++;				// increment number of tigers
			// create a new, larger array if necessary
			if (tigers > tigerArraySize) {
				tigerArraySize *= 2;
				Tiger *tigerTempArray = new Tiger[tigerArraySize];
				for (int i = 0; i < tigers - 1; i++) {
					tigerTempArray[i] = tigerArray[i];
				}
				delete []tigerArray;
				tigerArray = tigerTempArray;
			}
			funds -= adultTiger.getCost();
			std::cout << "You now have " << tigers << " tigers\n";
			tigerArray[tigers] = adultTiger;
		} else if (animalToBuy == 2) {
			Penguin adultPenguin(3);
			penguins++;
			if (penguins > penguinArraySize) {
				penguinArraySize *= 2;
				Penguin *penguinTempArray = new Penguin[penguinArraySize];
				for (int i = 0; i < penguins - 1; i++) {
					penguinTempArray[i] = penguinArray[i];
				}
				delete []penguinArray;
				penguinArray = penguinTempArray;
			}
			funds -= adultPenguin.getCost();
			std::cout << "You now have " << penguins << " penguins\n";
			penguinArray[penguins] = adultPenguin;
		} else if (animalToBuy == 3) {
			Turtle adultTurtle(3);
			turtles++;
			if (turtles > turtleArraySize) {
				turtleArraySize *= 2;
				Turtle *turtleTempArray = new Turtle[turtleArraySize];
				for (int i = 0; i < turtles - 1; i++) {
					turtleTempArray[i] = turtleArray[i];
				}
				delete []turtleArray;
				turtleArray = turtleTempArray;
			}
			funds -= adultTurtle.getCost();
			std::cout << "You now have " << turtles << " turtles\n";
			turtleArray[turtles] = adultTurtle;
		}
	}
}

/*
 ** Description: this function deletes the dynamic arrays at the end of the game
 */
void Zoo::clearArrays() {
	delete[] tigerArray;
	delete[] penguinArray;
	delete[] turtleArray;
}

/*
 ** Description: prompts the user to see if they would like to play again
 */
int Zoo::playAgain() {
	std::cout << "Enter 1 to keep playing, Enter 2 to exit.\n";
	return inputValidation(1, 2);
}

void Zoo::setFunds(int deposit) {
	funds = deposit;
}

int Zoo::getFunds() {
	return funds;
}

int Zoo::getTigers() {
	return tigers;
}

int Zoo::getPenguins() {
	return penguins;
}

int Zoo::getTurtles() {
	return turtles;
}
