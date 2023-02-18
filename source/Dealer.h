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
// Dealer : friend of Die class
//------------------------------------------------------------------------------
class Dealer {
private:
	Die die1, die2;
	bool resultIsEven;

	// allow << operator private access
	friend ostream& operator<<(ostream&, Dealer&);

public:
	Dealer();					// Constructor
	void rollDice(int&, int&);	// Put die values in reference parameters
	bool isResultEven() const;	// return true on Cho result, false on Han
	int getDie1Value() const;
	int getDie2Value() const;
};

//------------------------------------------------------------------------------
// overloaded << operator streams result string
//------------------------------------------------------------------------------
static ostream& operator<<(ostream& os, Dealer& d) {
	os << (d.resultIsEven ? "Cho (even)" : "Han (odd)");
	return os;
}
#endif

