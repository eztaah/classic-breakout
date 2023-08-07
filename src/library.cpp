#include "library.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>


// MATH FUNCTIONS
float myUtils::abs(float number) 
{
    return sqrt(number * number);
};


float myUtils::random()
{
    // Providing a seed value (using time() so each time it's different)
	srand((unsigned) time(NULL));

	// Get a random number
	int randomNumber = rand();

    return randomNumber;
}