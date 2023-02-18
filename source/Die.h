//------------------------------------------------------------------------------
// Die.h : class declaration/specification
//------------------------------------------------------------------------------
#ifndef DIE_H
#define DIE_H

class Die {
private:
   int sides;				// Number of die sides
   int value;				// The die's value

public:
   Die();					// Constructor
   Die(int);				// Constructor
   void roll();				// Rolls the die
   int getSides() const;	// Returns the number of sides
   int getValue() const;	// Returns the die's value
};
#endif