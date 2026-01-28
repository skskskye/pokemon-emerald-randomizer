#include <iostream>
#include <fstream>
#include "randomize.h"
#include "fileio.h"

int main(){
    const char* filename = "emerald-test.gba"; // the game file name [temp for now]     
    FileIO file(filename);

    randomize_starters(file);

    file.game.close();
    
    return 0;
}
