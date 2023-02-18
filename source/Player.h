//------------------------------------------------------------------------------
// Player.h : class declaration/specification
//
// Author: Tony Gaddis, Gaddis9e Ch.14
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#ifndef PLAYER_H
#define PLAYER_H

#include <ostream>
#include <string>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::ostream;
using std::string;

//------------------------------------------------------------------------------
// Player
//------------------------------------------------------------------------------
class Player {
private:
	string name;
	bool guessIsEven;
	int points;

	// allow << operator private access
	friend ostream& operator<<(ostream&, Player&);

public:
	Player();						// default constructor
	Player(const string&);			// overload constructor

	void setName(const string&);
	string getName() const;

	void makeGuess();				// Causes player to make a guess
	bool isGuessEven() const;		// Returns true on even guess, false on odd

	void addPoints(int);			// Adds points to the player
	int getPoints() const;			// Returns the player's points
};

//------------------------------------------------------------------------------
// overloaded << operator streams player name
//------------------------------------------------------------------------------
static ostream& operator<<(ostream& os, Player& p) {
	os << p.name;
	return os;
}
#endif
