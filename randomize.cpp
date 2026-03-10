#include "pokemon.h"
#include "species.h"
#include "fileio.h"
#include <iostream>
#include <cstdint>
#include <random>
#include <array>


//all relevant offsets
const uint32_t starterOffset = 0x5B1DF8;

uint16_t getRandomNumber(int low, int high){    

    std::random_device randn;
    std::mt19937 engine(randn());

    std::uniform_int_distribution<uint16_t> dist(low, high);

    uint16_t numb = dist(engine);
    return numb;

}
/*
TODO: make this function take in a object Pokemon, and add the hex to it, in Pokemon, make something so i can keep track of what pokemon is what, more so just to do some testing with it i suppose..
*/
uint16_t getRandomPokemon() { 

    uint16_t pokemon = getRandomNumber(1, 411);

    while(1) { 

        /*
        valid pokemons are from 1-251 and 277-411 TODO: make this cleaner lol
        */

        if(pokemon < 251) break;

        if(pokemon >= 277 && pokemon <= 411) break;

        //retrying for a new valid pokemon (there has to be a cleaner way of doing this LOL)
        pokemon = getRandomNumber(1, 411); 
    }

    

    return pokemon;
}

std::vector<Pokemon> randomizeStarters(FileIO& game) {
    std::vector<Pokemon> pokemons; 
    uint32_t currnet = starterOffset;
    for (uint32_t i = 0; i < 3; i++) {
        std::cout << i << std::endl;

        /* 
        TODO: fix bug with mew and other pokemon not obeying.... [creates a softlock in rare instances]
        SOMEHOW WITH THE POWER OF MAGIC PATCH THIS BUG OUT (??????????? ugh this will be not fun LOL)
        this will have to be fixed at the end of the project though.... this issue isnt to big of a deal since afaik only mew/deyoxes have this issue 
        */
        uint16_t randomPokemon = getRandomPokemon();
        
        game.writeToFile((currnet + (i * 2)) , randomPokemon);
        
        Pokemon p(randomPokemon, 3, 3);
        pokemons.push_back(p);
    }

    return pokemons;
}

void randomizeRoutes () { 
    // TODO: randomize routes
    
    return;

}