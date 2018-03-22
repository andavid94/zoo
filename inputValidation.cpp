/*
 ** Author: David An
 ** Date: Jan 31 2018
 ** Description: This function tests a user's input against the passed
 ** 			 min and max integers, and then returns the user input if
 **				 it falls within the given boundaries.
 */

#include "inputValidation.hpp"
#include <iostream>
#include <limits>

int inputValidation(int min, int max) {
	
	int input = 0;
	bool isValid = false;
	
	// re-prompt user until valid input is entered
	while (isValid == false) {
		// check if input is an integer
		if (std::cin >> input) {
			// if so, return the input if it lies within the boundaries
			if (input <= max && input >= min) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return input;
			}
		}
		// clear input stream and re-prompt user for new, valid input
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Your entry is invalid, please try again\n";
	}
	
	return input;
}
