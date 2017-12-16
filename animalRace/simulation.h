//
// Created by Phili on 12/16/2017.
//

#ifndef LEARNING_CPLUSPLUS_SIMULATION_H
#define LEARNING_CPLUSPLUS_SIMULATION_H

const int RACE_DISTANCE =70; // Define how long the race course is.

const int TIE_CODE=0; // If the race is a tie.
const in HARE_CODE=1; // If the Hare wins.
const int TORTOISE_CODE=2; // If the Tortoise wins.

extern int GetRandomInteger();
extern void moveTortoise(int *turtlePtr, int randomNumber);
extern void moveHare(int *rabbitPtr, int randomNumber);
extern std::string CreateEmptyRacetrack(const unsigned int len);
extern std::drawStringOfCurrentPosition(const int* snapperPtr, const int *bunnyPtr);
extern std::string HoldRace(int *winner, int *time);

#endif //LEARNING_CPLUSPLUS_SIMULATION_H
