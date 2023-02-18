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
Dealer::Dealer() { resultIsEven = false; }

//------------------------------------------------------------------------------
// - rolls both dice and saves their values
//------------------------------------------------------------------------------
void Dealer::rollDice(int& die1Value, int& die2Value) {
	die1Value = die1.roll();
	die2Value = die2.roll();

	resultIsEven = !((die1.value + die2.value) % 2);
}

//------------------------------------------------------------------------------
// returns the string result of the dice roll: Cho (even) or Han (odd).                           *
//------------------------------------------------------------------------------
bool Dealer::isResultEven() const { return resultIsEven; }

//------------------------------------------------------------------------------
// returns the value of die #1
//------------------------------------------------------------------------------
int Dealer::getDie1Value() const { return die1.value; }

//------------------------------------------------------------------------------
// returns the value of die #2
//------------------------------------------------------------------------------
int Dealer::getDie2Value() const { return die2.value; }
