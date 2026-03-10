#include <iostream>
#include <fstream>
#include <vector>
#include "randomize.h"
#include "fileio.h"
#include "pokemon.h"


int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    const char* filename = "emerald-test.gba"; // the game file name [temp for now]     
    FileIO file(filename);

    std::vector<Pokemon> pokemons = randomizeStarters(file);

    for (int i = 0; i < pokemons.size(); i++) { 
        std::cout << static_cast<char>(pokemons[i].getSpecie()) << std::endl; 
    }
     


    file.game.close();
    
    return 0;
}
