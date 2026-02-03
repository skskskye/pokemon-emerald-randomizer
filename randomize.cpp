#include "randomize.h"
#include "pokemon.h"
#include "fileio.h"
#include <iostream>
#include <cstdint>
#include <ctime>

//all relevant offsets
const uint32_t starterOffset = 0x5B1DF8;

uint16_t getRandomNumber(int low, int high){    
    // generate a random number
    uint16_t randomNum = rand() % (low-high) + high;


    
    return randomNum;
}

void randomize_starters(FileIO& game){
    uint32_t currnet = starterOffset;
    for (uint32_t i = 0; i < 3; i++) {
        std::cout << i << std::endl;
        game.writeToFile((currnet + (i * 2)) , getRandomNumber(1, 200));
    }
}