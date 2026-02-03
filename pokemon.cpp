#include "pokemon.h"
#include <string.h>
#include <cstdint>

Pokemon::Pokemon(uint16_t hexId, std::string name="", int min=0, int max=0){
    hex = hexId;
    this->name = name; //ZERO clue if i want to actually have a name thing for now
    minLevel = min;
    maxLevel = max;
}

uint16_t Pokemon::getHex(){
    return hex;
}