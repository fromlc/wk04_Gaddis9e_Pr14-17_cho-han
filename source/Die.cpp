//------------------------------------------------------------------------------
// Die.cpp : class definition/implementation
// 
// Author: Tony Gaddis, Gaddis9e Ch.14
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------

#include "Die.h"

#include <cstdlib>     // rand()

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int DEFAULT_SIDES = 6;
constexpr int MIN_ROLL = 1;

//------------------------------------------------------------------------------
// default constructor
// - calls overload constructor with default number of sides for die
//------------------------------------------------------------------------------
Die::Die() : Die(DEFAULT_SIDES) {}

//------------------------------------------------------------------------------
// overload constructor 
// - accepts number of sides for the die
// - performs a roll
//------------------------------------------------------------------------------
Die::Die(int numSides) : sides(numSides) { roll(); }

//------------------------------------------------------------------------------
// - simulates a die roll with random value from MIN_ROLL to number of sides
//------------------------------------------------------------------------------
int Die::roll() {

	value = (rand() % (sides - MIN_ROLL + 1)) + MIN_ROLL;
	return value;
}

//------------------------------------------------------------------------------
// getters
//------------------------------------------------------------------------------
int Die::getSides() const { return sides; }

int Die::getValue() const { return value; }

