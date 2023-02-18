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
// prototypes
//------------------------------------------------------------------------------
void roundResults(Dealer&, Player&, Player&);
void checkGuess(Player&, Dealer&);
void displayGrandWinner(Player, Player);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// Seed the random number generator.
	srand((unsigned int)time(0));

	// app banner
	cout << "\nWelcome to Cho-Han!\n\n";

	string player1Name, player2Name;

	// get the player's names
	cout << "Enter the first player's name: ";
	cin >> player1Name;
	cout << "Enter the second player's name: ";
	cin >> player2Name;

	// create the two players
	Player player1(player1Name);
	Player player2(player2Name);

	// create the dealer
	Dealer dealer;

	// play the rounds
	for (int round = 1; round <= MAX_ROUNDS; round++) {
		cout << "\n--------------------------------------------------\n";
		cout << "Round " << round << '\n';

		// roll the dice
		dealer.rollDice();

		// the players make their guesses
		player1.makeGuess();
		player2.makeGuess();

		// determine the winner of this round
		roundResults(dealer, player1, player2);
	}

	// display the grand winner
	displayGrandWinner(player1, player2);

	return 0;
}

//------------------------------------------------------------------------------
// determines the results of the current round
//------------------------------------------------------------------------------
void roundResults(Dealer& dealer, Player& player1, Player& player2) {

	// show the dice values
	cout << "The dealer rolled " << dealer.getDie1Value()
		<< " and " << dealer.getDie2Value(); 

	// show the result
	cout << ": " << dealer.getChoOrHan() << '\n';

	// check each player's guess and award points
	checkGuess(player1, dealer);
	checkGuess(player2, dealer);
}

//------------------------------------------------------------------------------
// checks a player's guess against the dealer's result
//------------------------------------------------------------------------------
void checkGuess(Player& player, Dealer& dealer) {

	// get the player's guess
	string guess = player.getGuess();

	// display the player's guess
	cout << player.getName() << " guessed " << guess << '.';

	// award points if the player guessed correctly
	if (!guess.compare(dealer.getChoOrHan())) {

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
void displayGrandWinner(Player player1, Player player2) {
	cout << "\n--------------------------------------------------\n";
	cout << "Game over. Here are the results:\n";

	// display player #1's results
	cout << player1.getName() << ": "
		<< player1.getPoints() << " points\n";

	// display player #2's results
	cout << player2.getName() << ": "
		<< player2.getPoints() << " points\n";

	// determine the grand winner
	if (player1.getPoints() > player2.getPoints()) 	{
		cout << player1.getName() << " is the grand winner!\n";
	}
	else if (player2.getPoints() > player1.getPoints()) {
		cout << player2.getName() << " is the grand winner!\n";
	}
	else {
		cout << "Both players are tied!\n";
	}
}