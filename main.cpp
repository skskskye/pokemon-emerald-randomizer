#include <iostream>
#include <fstream>

int main(){
    const char* filename = "emerald-test.gba"; // the game file name [temp for now]
    
    std::fstream game(filename, std::ios::out | std::ios::in | std::ios::binary); //writing to the game in binary mode

    if(!game){
        std::cerr << "Error occured while opening game file! perhaps... wrong thing ?";
    }

    //closing the file
    game.close(); 
    
    return 0;
}
