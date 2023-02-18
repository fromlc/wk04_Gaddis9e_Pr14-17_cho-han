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
// Constructor
//------------------------------------------------------------------------------
Player::Player(string playerName) : name(playerName), guess(""), points(0) { }

//------------------------------------------------------------------------------
// causes the player to guess either "Cho (even)" or "Han (odd)"
//------------------------------------------------------------------------------
void Player::makeGuess() {

   constexpr int MIN_VALUE = 0;
   constexpr int MAX_VALUE = 1;

   // Get a random number, either 0 or 1.
   int guessNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

   // Convert the random number to Cho or Han.
   guess = (guessNumber == 0) ? "Cho (even)" : "Han (odd)";
}

//------------------------------------------------------------------------------
// - adds the specified number of points to the player                            *
//------------------------------------------------------------------------------
void Player::addPoints(int newPoints) { points += newPoints; }

//------------------------------------------------------------------------------
// - returns the player's name
//------------------------------------------------------------------------------
string Player::getName() const { return name; }

//------------------------------------------------------------------------------
// returns the player's guess
//------------------------------------------------------------------------------
string Player::getGuess() const { return guess; }

//------------------------------------------------------------------------------
// returns the player's points
//------------------------------------------------------------------------------
int Player::getPoints() const { return points; }


