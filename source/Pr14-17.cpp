//------------------------------------------------------------------------------
// Pr14-17.cpp
// 
// This program simulates the game of Cho-Han with two players.
// Players guess whether the dealer will roll an even total with two dice.
// Points are awarded for each correct guess. The grand winner is displayed
// after all rounds are played.
// 
// Author: Gaddis9e Ch. 14 pp. 876-884
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "Dealer.h"
#include "Player.h"

#include <cstdlib>     // for srand()
#include <ctime>       // for time()
#include <iostream>
#include <string>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int MAX_ROUNDS = 5;		// number of rounds to play
constexpr int POINTS_TO_ADD = 1;	// points to award winner

//------------------------------------------------------------------------------
// namespace globals
//------------------------------------------------------------------------------
namespace game {
	Dealer dealer;
	Player player1, player2;
}

//------------------------------------------------------------------------------
// prototypes
//------------------------------------------------------------------------------
void roundResults();
void checkGuess(Player&);
void displayGrandWinner();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// Seed the random number generator.
	srand((unsigned int)time(0));

	// app banner
	cout << "\nWelcome to Cho-Han!\n\n";

	string name;

	// get the player's names
	cout << "Enter the first player's name: ";
	cin >> name;
	game::player1.setName(name);

	cout << "Enter the second player's name: ";
	cin >> name;
	game::player2.setName(name);

	// play the rounds
	for (int round = 1; round <= MAX_ROUNDS; round++) {
		cout << "\n--------------------------------------------------\n";
		cout << "Round " << round << '\n';

		// the players make their guesses
		game::player1.makeGuess();
		game::player2.makeGuess();

		// determine the winner of this round
		roundResults();
	}

	// display the grand winner
	displayGrandWinner();

	return 0;
}

//------------------------------------------------------------------------------
// determines the results of the current round
//------------------------------------------------------------------------------
void roundResults() {

	int die1Value, die2Value;

	// roll the dice
	game::dealer.rollDice(die1Value, die2Value);

	// show the dice values
	cout << "The dealer rolled " << die1Value
		<< " and " << die2Value;

	// show the result
	cout << ": " << game::dealer.getChoOrHan() << '\n';

	// check each player's guess and award points
	checkGuess(game::player1);
	checkGuess(game::player2);
}

//------------------------------------------------------------------------------
// checks a player's guess against the dealer's result
//------------------------------------------------------------------------------
void checkGuess(Player& player) {

	// get the player's guess
	string guess = player.getGuess();

	// display the player's guess
	cout << player.getName() << " guessed " << guess << '.';

	// award points if the player guessed correctly
	if (!guess.compare(game::dealer.getChoOrHan())) {

		player.addPoints(POINTS_TO_ADD);
		cout << " Awarding " << POINTS_TO_ADD << " point";

		if (POINTS_TO_ADD > 1) {
			cout << 's';
		}
		cout << " to " << player.getName() << '!';
	}

	cout << '\n';
}

//------------------------------------------------------------------------------
// displays the game's grand winner
//------------------------------------------------------------------------------
void displayGrandWinner() {
	cout << "\n--------------------------------------------------\n";
	cout << "Game over. Here are the results:\n";

	int points1 = game::player1.getPoints();

	// display player #1's results
	cout << game::player1.getName() << ": "
		<< points1 << " points\n";

	int points2 = game::player2.getPoints();

	// display player #2's results
	cout << game::player2.getName() << ": "
		<< points2 << " points\n";

	// determine the grand winner
	if (points1 > points2) {
		cout << game::player1.getName() << " is the grand winner!\n";
	}
	else if (points2 > points1) {
		cout << game::player2.getName() << " is the grand winner!\n";
	}
	else {
		cout << "Both players are tied!\n";
	}
}