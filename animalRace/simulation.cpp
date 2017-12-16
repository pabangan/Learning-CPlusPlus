//
// Created by Phili on 12/16/2017.
//

#include "simulation.h"

int GetRandomInteger()
{
    static std::default_random_engine engine{static_cast<unsigned int>(time(0))};
    static std::uniform_int_distribution<int> randomInt{1, 10};
    return randomInt(engine);
}

void moveTortoise(int *turtlePtr, int randomNumber)
{
    int i = randomNumber;
    if((1<=i) && (i<=5))
    {
        *turtlePtr += 3;
    }
    else if((6 <= i) && (i <= 7))
    {
        *turtlePtr -= 6;
        if (*turtlePtr < 1)
        {
            *turtlePtr = 1;
        }
    }
    else if ((8 <= i) && (i <= 10))
    {
        *turtlePtr += 1;
    }
}

void moveHare(int * rabbitPtr,  int randomNumber)
{
    int i = randomNumber;
    string move = "";
    if ((1 <= i) && (i <= 2))
    {
        move = "Sleep";
    }
    if ((3 <= i) && (i <= 4))
    {
        *rabbitPtr += 9;
        move = "Big Hop";
    }
    if (i == 5)
    {
        *rabbitPtr -= 12;
        move = "Big Slip";
        if (*rabbitPtr < 1)
        {
            *rabbitPtr = 1;
        }
    }
    if ((6 <= i) && (i <= 8))
    {
        *rabbitPtr += 1;
        move = "Small Hop";
    }
    if ((9 <= i) && (i <= 10))
    {
        *rabbitPtr -= 2;
        move = "Small slip";
        if (*rabbitPtr < 1)
        {
            *rabbitPtr = 1;
        }
    }
}

string CreateEmptyRacetrack(const unsigned int len)
{
    string Track = "|";
    for (unsigned int i=0; i<len; i++)
    {
        Track = Track + ".";
    }
    Track = Track + "|";
    return std::string (Track);
}

std::string drawStringOfCurrentPosition(const int * snapperPtr,
                                        const int * bunnyPtr)
{
    const string ouch("@");
    const string bunnyName("H");
    const string turtleName("T");

    string emptyRace = CreateEmptyRacetrack(RACE_DISTANCE);

    if (*snapperPtr == *bunnyPtr)
    {
        emptyRace[*snapperPtr] = ouch[0];
    }
    else
    {
        emptyRace[*snapperPtr] = turtleName[0];
        emptyRace[*bunnyPtr] = bunnyName[0];
    }
    return emptyRace;
}

std::string HoldRace(int *winner, int *timer)
{
    stringstream display;
    display << "ON YOUR MARK, GET SET\nBANG               !!!!"
            << "\nAND THEY'RE OFF    !!!!\n";

    int turtlePosition = 1;
    int harePosion = 1;
    int * turtlePtr = &turtlePosition;
    int * rabbitPtr = &harePosion;
    while ((* turtlePtr < RACE_DISTANCE) && (* rabbitPtr < RACE_DISTANCE))
    {
        --*timer;
        moveTortoise(turtlePtr, GetRandomInteger());
        moveHare(rabbitPtr, GetRandomInteger());
        cout << drawStringOfCurrentPosition(turtlePtr, rabbitPtr) << endl;
    }
    if (*turtlePtr > *rabbitPtr)
    {
        *winner = TORTOISE_CODE;
    }
    else if (*rabbitPtr > *turtlePtr)
    {
        *winner = HARE_CODE;
    }
    else
    {
        *winner = TIE_CODE;
    }

    return display.str();
}