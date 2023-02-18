//------------------------------------------------------------------------------
// Player.cpp : class definition/implementation
// 
// Author: Tony Gaddis, Gaddis9e Ch.14
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "Player.h"

#include <string>
using std::string;

//------------------------------------------------------------------------------
// overload constructor
//------------------------------------------------------------------------------
Player::Player(const string& playerName) :
	name(playerName), guessIsEven(0), points(0) { }

//------------------------------------------------------------------------------
// default constructor
//------------------------------------------------------------------------------
Player::Player() : Player("player") {}

//------------------------------------------------------------------------------
// sets player name
//------------------------------------------------------------------------------
void Player::setName(const string& _name) { name = _name; }

//------------------------------------------------------------------------------
// - returns the player's name
//------------------------------------------------------------------------------
string Player::getName() const { return name; }

//------------------------------------------------------------------------------
// causes the player to guess either "Cho (even)" or "Han (odd)"
//------------------------------------------------------------------------------
void Player::makeGuess() {

	// get a random number, either 0 or 1.
	guessIsEven = (rand() % 2) ? true : false;
}

//------------------------------------------------------------------------------
// returns true if the player's guess is even, false if guess is odd
//------------------------------------------------------------------------------
bool Player::isGuessEven() const { return guessIsEven; }

//------------------------------------------------------------------------------
// adds the specified number of points to the player                            *
//------------------------------------------------------------------------------
void Player::addPoints(int newPoints) { points += newPoints; }

//------------------------------------------------------------------------------
// returns the player's points
//------------------------------------------------------------------------------
int Player::getPoints() const { return points; }


