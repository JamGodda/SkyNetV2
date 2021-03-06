// SkyNetUpgrade.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> // the in and the out stream
#include <cstdlib> // this is where we get the random number generator from
#include <ctime> // we use this for the seeding of the random number geneator. The are based on a calculation which means...
// somthing has to chaange each time and since time is changing the random number generated is changed each time also.

using namespace std; // basically the libary that this draws from allows us to use simple commads instead of typing evverything out each time.

int main() // this is the start of the overall program
{
	srand(static_cast<unsigned int>(time(0))); //  Seed random number generator so that its not the same every time.
											   //  By using the time on the computer the numbers change based on time

	int TargetLoaction = rand() % 64 + 1; // Random number between 1 and 64
	int tries = 0; // Number of tries to find for the origional AI
	int Randomtries = 0; // Number of tries to find the target for random numbers guesses
	int Lineartries = 0; // Number of tries to find the target for linear guesses
	int Humantries = 0; // Number of tries to find the target for human guesses
	int Search; // Holds the number they guessed

	cout << "\tWelcome to SkyNet the bots are out searching please run the program to see location \n\n";
	system("pause");

	int Linear = 0; // holds the guess for linear
	int random = 0; // holds the guess for random
	int human = 0; // holds the guess for human

	int low = 0; // this defines the starting low number for the equation that the computer will run
	int high = 64; // this defines the starting high number for the equation that the computer will run
	int targetLocationPrediction; // this is the holder for each guess and will change each time until it is equal to the target location

	do // start of the do while loop and it forces the human to give at least one guess
	{
		cout << "Enter a guess as to where the target maybe: " << endl; // prompets the person to input a guess
		cin >> human; // input for human
		++Humantries; // add to human tries during each loop
		if (human > TargetLoaction) // compares the guess to the real number and decides if it is to high and runs the loop again
		{
			cout << "The enemy is not here you flesh bag better search lower.\n\n";
		}
		else if (human < TargetLoaction) // compares the guess to the real number and decides if it is to low and runs the loop again
		{
			cout << "The enemy is not here you flesh bag better search higher.\n\n";
		}
		else // do this if the guess is not to high or to low
		{
			cout << "\nTarget found. THANK GOD! That took forever I can see the gray hairs that sprouted while you tried to guess the targets location. Missiles firing........" << endl;
		}

	} while (human != TargetLoaction); // forces the loop to go again and again until the human guess is the same as TargetLoaction
	system("pause");


	do // The do while loop forces the program to run at least once and then again and again until the computer finds the right number

	{
		// Its a little different than what was done in class but it works and is less typing.
		//Basically the high is added to the low and then divided by two each time, the high or low is increased or decreased respectivly if the guess is two high or low.
		// During the next run though the number is either lower or higher depending on if the pervious guess was to high or to low.
		targetLocationPrediction = ((high + low) / 2); // the equation has () in it to make sure the computer does the equation correctly instead of just reading right to left.

		++tries; // Counts the number of tries the computer takes to get the right number. it is added to during each loop cycle
		cout << "\nSearching Sector: \n";
		cout << targetLocationPrediction;
		cout << "\n";
		
		if (targetLocationPrediction > TargetLoaction) // compares the guess to the real number and decides if it is to high and runs the loop again
		{
			cout << "The enemy is not here better search lower.\n\n";
			high = targetLocationPrediction; // changes the high number to the guess number that was to high
		}
		else if (targetLocationPrediction < TargetLoaction) // compares the guess to the real number and decides if it is to low and runs the loop again
		{
			cout << "The enemy is not here better search higher.\n\n";
			low = targetLocationPrediction; // changes the low number to the guess number that was to low
		}
		else // do this if the guess is not to high or to low
		{
			cout << "\nTarget found missiles firing........" << endl;
			//cout << "\nTries to find target: " << tries << "\n";
		}

	} while (targetLocationPrediction != TargetLoaction); // forces the loop to go again and again until the the targetLocationPrediction is the same as TargetLoaction
	system("pause"); // pauses the system so that else statment can be read instead of immideatly exiting the program

	for (int Linear = 0; Linear < TargetLoaction; Linear++) // runs the linear guess until it is equal with target location and add one each loop
	{
		cout << "Linear guess number: " << endl; 
		cout << Linear + 1 << endl;
		++Lineartries; // counts each linear try
	}
	cout << "Target eventually found missiles firing........" << endl;
	system("pause"); // pauses the system so that else statment can be read instead of immideatly exiting the program

	do // The do while loop forces the program to run at least once and then again and again until the computer finds the right number
	{
		random = rand() % 64 + 1; // creats new random numbers
		cout << "Random Guess: " << random << endl;
		++Randomtries; // add to random tiries

	} while (random != TargetLoaction); 
	cout << "Target eventually found missiles firing........" << endl;
	system("pause");

	

	cout << "\nJust to prove how bad eveything besides my AI is let me show you the number of guesses needed to find the target\n" << endl;
	cout << "AI attempts (ME): " << tries << "\n" << endl; // displays an out put message and the correct number of respective tries
	cout << "Stupid Random numbers: " << Randomtries << "\n" << endl; // displays an out put message and the correct number of respective tries
	cout << "Linear tries that were better than you: " << Lineartries << "\n" << endl; // displays an out put message and the correct number of respective tries
	cout << "You the stupid human:  " << Humantries << "\n" << endl; // displays an out put message and the correct number of respective tries
	system("pause");

	return 0; // returns an int to main since that what the type is.
}
