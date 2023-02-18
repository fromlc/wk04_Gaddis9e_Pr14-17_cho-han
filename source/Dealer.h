//------------------------------------------------------------------------------
// Dealer.h : class declaration/specification
// 
// Author: Tony Gaddis, Gaddis9e Ch.14
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#ifndef DEALER_H
#define DEALER_H

#include "Die.h"

#include <string>
using std::string;

//------------------------------------------------------------------------------
// Dealer
//------------------------------------------------------------------------------
class Dealer {
private:
	Die die1;             // Object for die #1
	Die die2;             // Object for die #2
	int die1Value;        // Value of die #1
	int die2Value;        // Value of die #2

public:
	Dealer();					// Constructor
	void rollDice();
	string getChoOrHan() const;	// Get the result (Cho or Han)
	int getDie1Value() const;
	int getDie2Value() const;
};
#endif

