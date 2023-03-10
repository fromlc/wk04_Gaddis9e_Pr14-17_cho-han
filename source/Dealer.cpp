//------------------------------------------------------------------------------
// Dealer.cpp : class definition/implementation
// 
// Author: Tony Gaddis, Gaddis9e Ch.14
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "Dealer.h"

//------------------------------------------------------------------------------
// Constructor
// - set the intial dice values to 0 (we won't use these values)
//------------------------------------------------------------------------------
Dealer::Dealer() { die1Value = die2Value = 0; }

//------------------------------------------------------------------------------
// - rolls both dice and saves their values
//------------------------------------------------------------------------------
void Dealer::rollDice() {
	die1Value = die1.roll();
	die2Value = die2.roll();
}

//------------------------------------------------------------------------------
// returns the string result of the dice roll: Cho (even) or Han (odd).                           *
//------------------------------------------------------------------------------
string Dealer::getChoOrHan() const {

	bool even = !((die1Value + die2Value) % 2);

	return even ? "Cho (even)" : "Han (odd)";
}

//------------------------------------------------------------------------------
// returns the value of die #1
//------------------------------------------------------------------------------
int Dealer::getDie1Value() const { return die1Value; }

//------------------------------------------------------------------------------
// returns the value of die #2
//------------------------------------------------------------------------------
int Dealer::getDie2Value() const { return die2Value; }
