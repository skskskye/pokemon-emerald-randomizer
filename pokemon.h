#pragma once

#include <string>
#include <iostream>
#include <cstdint>
#include "species.h"

class Pokemon
{


    private: 
        Species species;
        int minLevel;
        int maxLevel;
    public:
        Pokemon(uint16_t sp, int min, int max);
        int getMinLevel();
        int getMaxLevel();
        Species getSpecie();
};