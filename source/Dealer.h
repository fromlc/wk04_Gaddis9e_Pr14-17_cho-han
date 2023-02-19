//------------------------------------------------------------------------------
// Dealer.h : class declaration/specification
// 
// Author: Tony Gaddis, Gaddis9e Ch.14
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#ifndef DEALER_H
#define DEALER_H

#include "Die.h"

#include <ostream>
#include <string>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::ostream;
using std::string;


//------------------------------------------------------------------------------
// even or odd dice roll
//------------------------------------------------------------------------------
enum ChoHan { Cho = 0, Han = 1, NoDice = 2 };

//------------------------------------------------------------------------------
// Dealer : friend of Die class
//------------------------------------------------------------------------------
class Dealer {
private:
	Die die1, die2;
	ChoHan rollResult;

public:
	Dealer();						// Constructor
	ChoHan rollDice(int&, int&);	// Return roll result and die values
	ChoHan getRollResult() const;
};

//------------------------------------------------------------------------------
// overloaded << operator streams result string
//------------------------------------------------------------------------------
static ostream& operator<<(ostream& os, Dealer& d) {
	os << (d.getRollResult() == Cho ? "Cho" : "Han");
	return os;
}
#endif

