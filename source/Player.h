//------------------------------------------------------------------------------
// Player.h : class declaration/specification
//
// Author: Tony Gaddis, Gaddis9e Ch.14
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

//------------------------------------------------------------------------------
// Player
//------------------------------------------------------------------------------
class Player {
private:
	string name;
	string guess;
	int points;

public:
	Player();						// default constructor
	Player(const string&);			// overload constructor

	void setName(const string&);
	string getName() const;

	void makeGuess();				// Causes player to make a guess
	string getGuess() const;		// Returns the player's guess

	void addPoints(int);			// Adds points to the player
	int getPoints() const;			// Returns the player's points
};
#endif
