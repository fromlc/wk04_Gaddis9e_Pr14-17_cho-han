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
const string DIVIDER = "\n--------------------------------------------------\n";

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
void initGame();
void getPlayerNames();
void playChoHan();
void roundResults();
void checkGuess(Player&);
void displayGrandWinner();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	initGame();

	playChoHan();

	displayGrandWinner();

	return 0;
}

//------------------------------------------------------------------------------
// initialize game environment
//------------------------------------------------------------------------------
void initGame() {

	// Seed the random number generator.
	srand((unsigned int)time(0));

	// app banner
	cout << "\nWelcome to Cho-Han!\n\n";

	getPlayerNames();
}

//------------------------------------------------------------------------------
// get player names from user input
//------------------------------------------------------------------------------
void getPlayerNames() {

	string name;

	// get the player's names
	cout << "Enter the first player's name: ";
	cin >> name;
	game::player1.setName(name);

	cout << "Enter the second player's name: ";
	cin >> name;
	game::player2.setName(name);
}

//------------------------------------------------------------------------------
// loop to play game rounds
//------------------------------------------------------------------------------
void playChoHan() {

	for (int round = 1; round <= MAX_ROUNDS; round++) {
		cout << DIVIDER;
		cout << "\nRound " << round << '\n';

		// the players make their guesses
		game::player1.makeGuess();
		game::player2.makeGuess();

		// determine the winner of this round
		roundResults();
	}
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
	cout << ": " << game::dealer << '\n';

	// check each player's guess and award points
	checkGuess(game::player1);
	checkGuess(game::player2);
}

//------------------------------------------------------------------------------
// checks a player's guess against the dealer's result
//------------------------------------------------------------------------------
void checkGuess(Player& player) {

	// get the player's guess
	bool guessedEven = player.isGuessEven();
	string guess = guessedEven ? "Cho (even)" : "Han (odd)";

	// display the player's guess
	cout << player << " guessed " << guess << '.';

	// award points if the player guessed correctly
	if (!(guessedEven xor game::dealer.isResultEven())) {

		player.addPoints(POINTS_TO_ADD);
		cout << " Awarding " << POINTS_TO_ADD << " point";

		if (POINTS_TO_ADD > 1) {
			cout << 's';
		}
		cout << " to " << player << '!';
	}
	cout << '\n';
}

//------------------------------------------------------------------------------
// displays the game's grand winner
//------------------------------------------------------------------------------
void displayGrandWinner() {

	cout << DIVIDER;
	cout << "Game over. Here are the results:\n";

	int points1 = game::player1.getPoints();

	// display player #1's results
	cout << game::player1 << ": "
		<< points1 << " points\n";

	int points2 = game::player2.getPoints();

	// display player #2's results
	cout << game::player2 << ": " << points2 << " points\n";

	// determine the grand winner
	if (points1 == points2) {
		cout << "Both players are tied!\n";
		return;
	}

	cout << (points1 > points2 ? game::player1 : game::player2)
		<< " is the grand winner!\n";
}