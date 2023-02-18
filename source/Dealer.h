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
using std::ostream;
using std::string;

//------------------------------------------------------------------------------
// Dealer : friend of Die class
//------------------------------------------------------------------------------
class Dealer {
private:
	Die die1;             // Object for die #1
	Die die2;             // Object for die #2
	bool resultEven;

	friend ostream& operator<<(ostream&, Dealer&);

public:
	Dealer();					// Constructor
	void rollDice(int&, int&);	// Put die values in reference parameters
	string getChoOrHan() const;	// Get the result (Cho or Han)
	int getDie1Value() const;
	int getDie2Value() const;

};

//------------------------------------------------------------------------------
// overload << operator to display result
//------------------------------------------------------------------------------
static ostream& operator<<(ostream& os, Dealer& d) {
	os << d.resultEven ? "Cho (even)" : "Han (odd)";
	return os;
}
#endif

