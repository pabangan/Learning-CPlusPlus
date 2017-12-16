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