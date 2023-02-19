//------------------------------------------------------------------------------
// Pr14-17.cpp
// 
// This program simulates the game of Cho-Han with two players, a dealer,
// and two dice. In each round, players guess whether the dealer will roll
// an even total (Cho) or and odd total (Han). Points are awarded for each
// correct guess. The grand winner is displayed after all rounds are played.
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
constexpr int ROUNDS = 5;			// number of rounds to play
constexpr int POINTS = 1;			// points to award winner
const string DIVIDER = "\n--------------------------------------------------\n";

//------------------------------------------------------------------------------
// namespace globals
//------------------------------------------------------------------------------
namespace game {
	Dealer dealer;
	ChoHan rollResult;
	Player player1, player2;
}

//------------------------------------------------------------------------------
// prototypes
//------------------------------------------------------------------------------
void initGame();
void getPlayerNames();
void playChoHan();
void playARound();
int checkGuess(Player&);
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
	cout << "\nWelcome to the ancient dice game of Cho-Han!\n\n";
	cout << "An even roll is Cho, an odd roll is Han.\n";
	cout << "The Dealer will roll the dice " << ROUNDS << " times.\n";
	cout << "Players will guess Cho or Han before each roll.\n";
	cout << "Each correct guess is worth " << POINTS << " point";
	if (POINTS > 1) {
		cout << 's';
	}
	cout << ". Good luck!\n\n";

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

	for (int round = 1; round <= ROUNDS; round++) {
		cout << DIVIDER;
		cout << "\nRound " << round << '\n';

		// determine the winner of this round
		playARound();
	}
}

//------------------------------------------------------------------------------
// determines the results of the current round
//------------------------------------------------------------------------------
void playARound() {

	int die1Value, die2Value;

	// roll the dice
	game::rollResult = game::dealer.rollDice(die1Value, die2Value);

	// show the roll result
	cout << "Dealer rolled " << die1Value << " and " << die2Value
		<< ". " << die1Value + die2Value << " is " << game::dealer
		<< "!\n";

	// check each player's guess and award points
	int points1 = checkGuess(game::player1);
	int points2 = checkGuess(game::player2);

	// show current score
	cout << "Score so far: " << game::player1 << ' ' << points1
		<< ", " << game::player2 << ' ' << points2 << '\n';
}

//------------------------------------------------------------------------------
// - checks a player's guess against the dealer's result
// - returns number of points awarded
//------------------------------------------------------------------------------
int checkGuess(Player& player) {

	// get the player's guess
	ChoHan guess = player.makeGuess();
	string guessStr = Cho ? "Cho" : "Han";
	int pointsAwarded = 0;

	// display the player's guess
	cout << player << " guessed " << guessStr << '.';

	// award points if the player guessed correctly
	if (guess == game::rollResult) {

		pointsAwarded = POINTS;
		player.addPoints(POINTS);

		cout << " Awarding " << POINTS << " point";

		if (POINTS > 1) {
			cout << 's';
		}
		cout << " to " << player << '!';
	}
	cout << '\n';

	return pointsAwarded;
}

//------------------------------------------------------------------------------
// displays the game's grand winner
//------------------------------------------------------------------------------
void displayGrandWinner() {

	cout << DIVIDER;
	cout << "Game over. Here are the results:\n";

	int points1 = game::player1.getPoints();

	// display player #1's results
	cout << game::player1 << " has " << points1 << " points\n";

	int points2 = game::player2.getPoints();

	// display player #2's results
	cout << game::player2 << " has " << points2 << " points\n";

	// determine the grand winner
	if (points1 == points2) {
		cout << "Both players are tied!\n";
		return;
	}

	cout << (points1 > points2 ? game::player1 : game::player2)
		<< " is the Grand Winner!\n";
}