#include<iostream>
#include<ctime>
#include<iomanip>
#include<string>

using namespace std;

const int WHITEBALLS_MAX = 69; //max number for white balls
const int POWERBALL_MAX = 26; //max number for powerball
const int WHITEBALL_ARRAY = 5; //size of array for white balls
const int POWERBALL_ARRAY = 1; //size of the array for power ball
const int WHITE_MATCH_SIZE = 6; // size of matching white balls
const int POWER_MATCH_SIZE = 2; //size of matching power ball

const int winning[POWER_MATCH_SIZE][WHITE_MATCH_SIZE] = { {0,0,0,7,100,100000 } ,{4, 4, 7, 100, 50000, 1000000000} }; //finding the winning in array





void displayArt();

void userInput(int user[], int WHITEBALL_ARRAY, string first, string last);

void userPowerBall(int userPower[], int size2);

void displayUserBall(int user[], int userPower[], int size);

void whiteBallRandom(int white[], int size);

void powerBallRandom(int actualPB[], int size2);

void displayWhiteBall(int white[], int actualPB[], int size);

int matchingWBalls(int user[], int white[], int size, int &matchWhiteCount);

int matchingPBalls(int userPower[], int actualPB[], int size2, int &matchPBallCount);

void displayWin(int &matchWhiteCount, int  &matchPBallCount);

int main() {

	int yourTicket[WHITEBALL_ARRAY],
		whiteBall[WHITEBALL_ARRAY],
		userPB[POWERBALL_ARRAY],
		powerBall[POWERBALL_ARRAY],
		matchWhite = 0,
		matchPower = 0;
	
	string firstName, lastName;
	
	displayArt(); //display my beautiful logo banner
	userInput(yourTicket, WHITEBALL_ARRAY, firstName, lastName); //calling for user's input and infomation.
	userPowerBall(userPB, POWERBALL_ARRAY); // user enter their powerball number
	displayUserBall(yourTicket, userPB, WHITEBALL_ARRAY);// display white ball from the user input
	whiteBallRandom(whiteBall, WHITEBALL_ARRAY); //generate random white ball number for lottery
	powerBallRandom(powerBall, POWERBALL_ARRAY); //generate a random powerball number for loto
	displayWhiteBall(whiteBall, powerBall, WHITEBALL_ARRAY); //display white ball AND also powerball
	matchingWBalls(yourTicket, whiteBall, WHITEBALL_ARRAY, matchWhite); //matching the white balls
	matchingPBalls(userPB, powerBall, POWERBALL_ARRAY, matchPower); //matching the power ball
	displayWin(matchWhite, matchPower);
				
	return 0;
}
//==========================================================================
//                                 Banner
//==========================================================================
void displayArt() {
	cout << "===================================================================================" << endl;
	cout << "                     WELCOME TO THE LOTTERY GAME: POWERBALL!                       " << endl;;
	cout << "===================================================================================" << endl;

}
//==========================================================================
//Name: userInput
//
//Pre: an array for the user's input, size of the array, string for user's names
//
//Post: The function as for the user's first name and last, name then an array is
//set up to ask for user's input then the if statment verifies the user's number
//after that the function lists the user's number.
//==========================================================================
void userInput(int user[], int WHITEBALL_ARRAY, string first, string last) {
	int num;
	bool checkDup[70] = { 0 }; // to check for duplicates


	cout << "Please enter your FIRST and LAST name..." << endl;
	cin >> first >> last;

	for (int i = 0; i < WHITEBALL_ARRAY; i++)
	{
		cout << "Enter your number... " << endl;
		cin >> num;

		if ((num >= 1) && (num <= 69))
		{
			if (checkDup[num] == false)
			{
				user[i] = num;
				checkDup[num] = true; //flagged true 
			}

			else
			{
				cout << "Number has already been used..." << endl;
				i--;
			}
		}

		else
		{
			cout << "Numbers from 0-9 only..." << endl;
			i--;
		}
	}


}
//==========================================================================
//Name: userPowerBall
//
//Pre: getting the array with size one to let user put in
//a number in the array
//
//Post: user put a number in the array for their powerball.
//==========================================================================
void userPowerBall(int userPower[], int size2) {
	int num, i=0;

	for (int i = 0; i < POWERBALL_ARRAY; i++) {
		cout << "Now enter your Powerball number..." << endl;
		cin >> num;

		if ((num >= 1) && (num <= 26)) {
			userPower[i] = num;
		}
		else {
			i--;
			cout << "Number is out of range..." << endl;
		}
	}
}
//==========================================================================
//Name: displayWhiteBall
//
//Pre: none
//
//Post: Display the numbers of the user's inputs
//==========================================================================
void displayUserBall(int user[], int userPower[],  int size) {

	cout << "Your Numbers are..." << endl;
	for (int i = 0; i < WHITEBALL_ARRAY; i++) {
		cout << user[i] << " ";
	}
	cout << endl;
	cout << "Your Powerball number is..." << endl;
	cout << userPower[0];
		
}
//==========================================================================
//Name: whiteBallRandom
//
//Pre: random number generator, array that contains size 5, and a do while
//loop to check for dupicate genrated numbers.
//
//Post: this function generates white balls without any duplicate numbers
//through a loop.
//==========================================================================
void whiteBallRandom(int white[], int size){

srand(time(NULL));

for (int i = 0; i < WHITEBALL_ARRAY; i++)
{
	bool check; 
	int num; 

	do
	{
		num = 1 + rand() % WHITEBALLS_MAX;
		//check or number is already used:
		check = true;
		for (int j = 0; j < i; j++)
			if (num == white[j]) //if number is already used
			{
				check = false; //set check to false
			}
	} while (!check); //loop until there is a unique number
	white[i] = num; //store the generated number in the array
}
}//==========================================================================
//Name: powerBallRandom
//
//Pre: random number gen. with array for pb
//
//Post: Putting unqiue random number into the pb array
//===========================================================================
void powerBallRandom(int actualPB[], int size2) {

	srand(time(NULL));

	for (int i = 0; i < POWERBALL_ARRAY; i++) {
		actualPB[i] = 1 + rand() % POWERBALL_MAX;

	}
}
//==========================================================================
//Name: displayWhiteBall
//
//Pre: none
//
//Post: display output of white ball array and powerball array.
//==========================================================================
void displayWhiteBall(int white[], int actualPB[], int size) {
	cout << endl;
	cout << "The lottery white balls are..." << endl;
	for (int i = 0; i < WHITEBALL_ARRAY; i++) {
		cout << white[i] << " ";
	}
	cout << endl;
	cout << "The lottery Powerball is..." << endl;
	for (int i = 0; i < POWERBALL_ARRAY; i++) {
		cout << actualPB[i] << endl;
	}
}
//==========================================================================
//Name: matchingWBalls
//
//Pre: getting user input, and random number gen array and check for matching
//
//Post: everytime the user input there wb number and the random num gen, randomized
//for white balls, the function tries to match and the counter is added by 1.
//==========================================================================
int matchingWBalls(int user[], int white[], int size, int &matchWhiteCount) {

	for (int i = 0; i < WHITEBALL_ARRAY; i++) 
		for (int j = 0; j < WHITEBALL_ARRAY; j++) {
			if (user[i] == white[j]) {
				matchWhiteCount++;

			}
		}


	return matchWhiteCount;
	
}
//==========================================================================
//Name: matchingPBalls
//
//Pre: getting user input, and random number gen array and check for matching
//
//Post: everytime the user input there pb number and the random num gen, randomized
//for power ball, the function tries to match and the counter is added by 1.
//==========================================================================
int matchingPBalls(int userPower[], int actualPB[], int size2, int &matchPBallCount) {

	for (int i = 0; i < POWERBALL_ARRAY; i++)
		for (int j = 0; j < POWERBALL_ARRAY; j++) {
			if (userPower[i] == actualPB[j]) {
				matchPBallCount++;
			}
		}
	return matchPBallCount;
}
//==========================================================================
//Name: displayWin
//
//Pre: getting white match count and match pb count
//then we assign those to a variable (i, j) and the user matches
//can output their prize form the 2d array
//
//Post: match counters will determin the player's win and the amount they get
//if user get 5 matches for wb and 1 for pb then jackpot will pop up.
//==========================================================================
void displayWin(int &matchWhiteCount, int  &matchPBallCount) {

	int i, j;

	cout << "________________________________________________________________________" << endl;
	cout << "You have " << matchWhiteCount << " white ball(s) matching." << endl;
	cout << "You have " << matchPBallCount << " power ball matching." << endl;

	j = matchWhiteCount;
	i = matchPBallCount;

	if (i == 0 && j <= 2) {
		cout << "You lose..." << endl;
	}
	else
		if (0 <= i && 0 <= j) {
			cout << "CONGRATULATION, You won..." << "$" << winning[i][j] << endl;
		}

	if (i == 1 && j == 5) {
		cout << "\n\n";
		cout << "====================================" << endl;
		cout << "HOLY $%#@, You have won the jackpot!" << endl;
		cout << "====================================" << endl;
	}

}

