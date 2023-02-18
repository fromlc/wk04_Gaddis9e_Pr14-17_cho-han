//------------------------------------------------------------------------------
// Die.h : class declaration/specification
//------------------------------------------------------------------------------
#ifndef DIE_H
#define DIE_H

//------------------------------------------------------------------------------
// Die
//------------------------------------------------------------------------------
class Die {
private:
   int sides;				// Number of die sides
   int value;				// The die's value

public:
   Die();					// Constructor
   Die(int);				// Constructor
   int roll();				// Rolls the die and returns the die's value
   int getSides() const;	// Returns the number of sides
   int getValue() const;	// Returns the die's value
};
#endif