/*
 ** Author: David An
 ** Date: Jan 30 2018
 ** Description: This program simulates a Zoo with different animals exhibiting
 ** 			 different behaviors. The program will keep track of the animal counts,
 ** 			 maintenence costs, and profits associated with the animals.
 */

#include <iostream>
#include <cstdlib>
#include "Zoo.hpp"
#include "inputValidation.hpp"

int main(){
	
	Zoo zoo;			// create zoo object
	zoo.setup();		// prompt user to set up the zoo
	
	// generate different random numbers every time
	srand(static_cast<unsigned int>(time(NULL)));
	
	int response;
	
	do {
		zoo.simulateDay();   // increase the age of each animal by 1
		zoo.randomEvent();	 // execute a random event
		zoo.endOfDay();		 // calculate and present information to user
		
		if (zoo.getFunds() < 0) {
			std::cout << "You have run out of money!\n";
			zoo.clearArrays();
			return 0;
		}
		
		response = zoo.playAgain();
		std::cout << std::endl;
	}
	while (response == 1);	 // loop as long as the user enters '1'
	zoo.clearArrays();
	return 0;
}
