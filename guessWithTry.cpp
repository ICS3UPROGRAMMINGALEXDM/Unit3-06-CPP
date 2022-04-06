// Copyright (c) 2022 Alex De Meo All rights reserved
//
// Created By: Alex De Meo
// Date: 03/30/22
// Description: In this program you will have to
// guess a randomly generated number correctly
//
#include <stdlib.h>
#include <random>

#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

// Defines the colors to use in the program
#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */

int main() {
    // declaring vars
    string uNum, answer;
    int rNum, uNumInt;
    bool keepPlaying = true, numIncorrect = true, answerIncorrect = true;

    // Loop to run the game  if the user responds yes later down the line
    while (keepPlaying == true) {
        // creating the random number
        std::random_device rseed;
        std::mt19937 rgen(rseed());
        std::uniform_int_distribution<int> idist(1, 15);
        rNum = idist(rgen);

        // shows number for testing purposes
        cout << rNum << std::endl;
        cout <<
        "I have just generated a random number " <<
        "between 1-15. Can you Guess it correctly?"
        << endl;

        // for startin the next loop
        numIncorrect = true;

        // loop allows user to continue guessing until they get it correctly
        while (numIncorrect == true) {
            // Getting user guess
            cout << "Guess a number: ";
            cin >> uNum;

            try {
                // casting to int
                uNumInt = std::stoi(uNum);

                // Comparing guess with number
                if (rNum == uNumInt) {
                    cout << BOLDGREEN <<
                    "Congratulations, you guessed the number correctly!!"
                    << RESET << endl;

                    // stops loop
                    numIncorrect = false;

                    while (answerIncorrect == true) {
                        cout << "Would you like to play again? (y/n): ";
                        cin >> answer;

                        // if statement for the answer
                        if (answer == "y") {
                            cout << "Okay\n";
                            break;

                        } else if (answer == "n") {
                            cout<< "Okay\n";
                            break;
                        } else {
                            cout <<
                            "That wasn't one of the options. Try again. \n";
                        }
                    }
                } else {
                    cout << BOLDRED << "Wrong Number! try again \n" << RESET;
                }
            } catch (std::invalid_argument) {
                cout << BOLDRED <<
                "Invalid number. Try again." << RESET << endl;
            }

            if (answer == "n") {
                break;
            }
        }
        if (answer == "n") {
            break;
        }
    }
}
