//
// Created by Phili on 12/16/2017.
//

#include <iostream>
#include <vector>

using namespace std;

#include "simulation.h"

int main(int argc, char *argv[])
{
    //Initializations
    int currentWinner = TIE_CODE;
    int timer=30000;
    //The functions required a reference parameter, so I had to make pointers
    //so that I could I access the pre-made functions.
    int *winnerPtr = &currentWinner;
    int *timePtr = &timer;
    //This function should run until there is a winner.
    HoldRace(winnerPtr, timePtr);
    //Switch statement is used to print who the winner is.
    switch(*winnerPtr)
    {
        case TORTOISE_CODE:
            //TODO: Print message
            cout << "TORTOISE WINS! YAY!!! " << endl;
            break;
        case HARE_CODE:
            //TODO: Print message
            cout << "Hare wins. Yuch. " << endl;
            break;
        case TIE_CODE:
            //TODO: Print message
            cout << "It's a tie. " << endl;
            break;
        default:
            cout << "ERROR: Invalid winner found." << endl;
    }
    //Here I had to subtract from 30,000 because it was given to us as that.
    //TODO:  Print time elapsed information
    cout << "TIME ELAPSED: " << 30000-*timePtr << " seconds" << endl;
    return EXIT_SUCCESS;
}
