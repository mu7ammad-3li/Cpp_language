//============================================================================
// Name        : ChipsGame_final.cpp
// Author      : Muhammad Ali
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <array>
#include <iomanip>
using namespace std;

// Create Player Structure

struct player {
	string name = " ";
	int noOfWins = 0;
};

// Global variables

const int MAX_CHIPS = 100;
const float MAX_TURN = 0.5;

// Start Output file stream

ofstream dashBoard;

// Function
//gets players' names
void findPlayerNames(array<player, 2> &arr);
// exports Game data to File
void exportData(array<player, 2> &arr,string winner ,int winnerMoves);
//Formats user input all to all caps
char userCheck(char choice);
//return active player's name
string findPlayer(array<player, 2> &arr, bool turn);
//ask active player to move chips
int askMove(array<player, 2> &arr, bool player1Turn, int chipsInPile);
//finds winner at the end of the game
string findWinner(array<player, 2> &arr,bool player1Turn);

int main() {
	//open Dashboard.txt
	dashBoard.open("Dashboard.txt", ios::app);

	srand(time(0));

	bool player1Turn = true;
	bool gameOver = false;
	int chipsInPile = 0;
	int chipsTaken = 0;
	char userChoice = 'n';
	int movesCounter = 0;
	string winner = " ";
	int winnerMoves ;

	array<player, 2> players;

	cout << "Chips Game \n " << endl; // prints Chips Game

	findPlayerNames(players);
	do {
		chipsInPile = (rand() % MAX_CHIPS) + 1;
		player1Turn =(rand()%2);
		cout << " This round starts with " << chipsInPile << " Chips " << endl;
		gameOver = false;
		movesCounter = 0;
		winnerMoves =0;
		while (gameOver == false) {
			chipsTaken = askMove(players, player1Turn, chipsInPile);
			chipsInPile = chipsInPile - chipsTaken;
			cout << "Chips left " << chipsInPile << " Chip" << endl;
			if (chipsInPile == 0) {
				gameOver = true;
				cout << "GAME OVER " << endl;
				cout << findPlayer(players, player1Turn) << " Wins "
						<< endl;
				winnerMoves = (movesCounter / 2) + 1;
				winner = findWinner(players, player1Turn);


				cout << "Do you want a Re-match ? Y" << endl;
				cin >> userChoice;
				userChoice = userCheck(userChoice);

			}
			else {
				player1Turn = !player1Turn;
				movesCounter++;
			}

		}
		exportData(players,winner,winnerMoves);
	} while (userChoice == 'Y');

dashBoard.close(); // closes file stream
	return 0;
}


// function Definitions
//...
void findPlayerNames(array<player, 2> &arr) {
	cout << "First Player => ";
	cin >> arr[0].name;
	cout << "Second Player => ";
	cin >> arr[1].name;

}

void exportData(std::array<player, 2> &arr,string winner ,int winnerMoves)
{
	dashBoard<<"**************************************************************\n";
	dashBoard << setw(20) << "Game between  * " << setw(16) << arr[0].name
			<< " * VS * " << setw(16) << arr[1].name << " *" << endl;
	dashBoard << setw(20) << "no.Of wins * " << setw(16) << arr[0].noOfWins
			<< " * " << setw(21) << arr[1].noOfWins << " *" << endl;
	dashBoard <<winner<<" Wins at "<<winnerMoves<<" Moves "<<endl;

}

string findPlayer(array<player, 2> &arr, bool turn) {
	if (turn == true)
		return arr[0].name;
	else
		return arr[1].name;
}
int askMove(array<player, 2> &arr, bool player1Turn, int chipsInPile) {
	int chipsTaken;
	int maxShare = chipsInPile * MAX_TURN;
	do {
		cout << findPlayer(arr, player1Turn)
				<< " How many chips would you like ?\n ";

		cout << "You can only take up to ";
		if (maxShare < 2) {
			cout << "1 chip " << endl;
		} else {
			cout << maxShare << " chips " << endl;
		}

		cin >> chipsTaken;

	} while ((chipsTaken > maxShare) && (chipsInPile > 1));
	return chipsTaken;
}
char userCheck(char choice) {
	if (islower(choice))
		return (choice - 32);
	else
		return choice;
}
string findWinner(array<player, 2> &arr,bool player1Turn)
{
	if (player1Turn == true)
	{
		arr[0].noOfWins++;
		return arr[0].name;
	}

	else
	{
		arr[1].noOfWins++;
		return arr[1].name;
	}

}
