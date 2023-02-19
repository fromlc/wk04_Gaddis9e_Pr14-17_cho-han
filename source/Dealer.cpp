//------------------------------------------------------------------------------
// Dealer.cpp : class definition/implementation
// 
// Author: Tony Gaddis, Gaddis9e Ch.14
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "Dealer.h"

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
Dealer::Dealer() { rollResult = NoDice; }

//------------------------------------------------------------------------------
// - rolls dice and saves their values
// - returns result of dice roll: Cho (even) or Han (odd).                           *
//------------------------------------------------------------------------------
ChoHan Dealer::rollDice(int& die1Value, int& die2Value) {
	die1Value = die1.roll();
	die2Value = die2.roll();

	rollResult = !((die1.value + die2.value) % 2) ? Cho : Han;
	return rollResult;
}

//------------------------------------------------------------------------------
// returns result of last dice roll: Cho (even) or Han (odd).                           *
//------------------------------------------------------------------------------
ChoHan Dealer::getRollResult() const { return rollResult; }

