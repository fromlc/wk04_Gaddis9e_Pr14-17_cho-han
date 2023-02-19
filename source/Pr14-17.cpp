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
	int score1 = 0;				// player1 score so far
	int score2 = 0;				// player2 score so far
}

//------------------------------------------------------------------------------
// prototypes
//------------------------------------------------------------------------------
void initGame();				// banner, instructions, game setup
void getPlayerNames();
void playChoHan();				// game loop
void playARound();
ChoHan doGuess(Player&);		// make and display a guess, return the guess
int scorePlayer(Player& player, ChoHan guess);	// return player score so far
void displayGrandWinner();
int showScore(Player&);
void inline addS(int);

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
	cout << "Players guess Cho or Han before each roll.\n";
	cout << "Each correct guess is worth " << POINTS << " point";
	addS(POINTS);
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

	ChoHan guess1 = doGuess(game::player1);
	ChoHan guess2 = doGuess(game::player2);

	int die1Value, die2Value;

	// roll the dice
	game::rollResult = game::dealer.rollDice(die1Value, die2Value);

	// show the roll result
	cout << "Dealer rolled " << die1Value << " and " << die2Value
		<< ". " << die1Value + die2Value << " is " << game::dealer
		<< "!\n";

	// check each player's guess and award points
	game::score1 = scorePlayer(game::player1, guess1);
	game::score2 = scorePlayer(game::player2, guess2);

	// show current score
	cout << "Score so far: " << game::player1 << ' ' << game::score1
		<< ", " << game::player2 << ' ' << game::score2 << '\n';
}

//------------------------------------------------------------------------------
// - player makes a guess
// - displays player's guess
// - returns the guess
//------------------------------------------------------------------------------
ChoHan doGuess(Player& player) {

	ChoHan guess = player.makeGuess();

	cout << player << " guessed ";

	if (guess == Cho) {
		cout << "Cho";
	}
	else {
		cout << "Han";
	}
	cout << ".\n";

	return guess;
}

//------------------------------------------------------------------------------
// - checks a player's guess against the dealer's result
// - returns player's score so far
//------------------------------------------------------------------------------
int scorePlayer(Player& player, ChoHan guess) {

	// award points if the player guessed correctly
	if (guess == game::rollResult) {

		player.addPoints(POINTS);

		cout << "Awarding " << POINTS << " point";
		addS(POINTS);
		cout << " to " << player << ".\n";
	}

	return player.getPoints();
}

//------------------------------------------------------------------------------
// displays the game's grand winner
//------------------------------------------------------------------------------
void displayGrandWinner() {

	cout << DIVIDER;
	cout << "\nGame over! Here are the results:\n";

	int points1 = showScore(game::player1);
	int points2 = showScore(game::player2); 

	// determine the grand winner
	if (points1 == points2) {
		cout << "Both players are tied!\n";
		return;
	}

	cout << (points1 > points2 ? game::player1 : game::player2)
		<< " is the Grand Winner!\n";
}

//------------------------------------------------------------------------------
// display player score
//------------------------------------------------------------------------------
int showScore(Player& player) {
	int points = player.getPoints();

	cout << player << " has " << points << " point";
	addS(points);
	cout << '\n';

	return points;
}

//------------------------------------------------------------------------------
// display an s on plural
//------------------------------------------------------------------------------
void inline addS(int points) {
	if (points > 1) {
		cout << 's';
	}
}
