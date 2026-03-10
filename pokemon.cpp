#include "pokemon.h"
#include <string.h>
#include <cstdint>

Pokemon::Pokemon(uint16_t sp, int min=0, int max=0)
    : species(static_cast<Species>(sp)), minLevel(min), maxLevel(max)
{}

int Pokemon::getMinLevel() { 
    return this->minLevel;
}

int Pokemon::getMaxLevel() { 
    return this->maxLevel;
}

Species Pokemon::getSpecie() { 
    return this->species;
}
