#include "fileio.h"
#include <cstdint>
#include <iostream>

std::string gameTitle = "42 50 45 45"; //BPEE <-- the game

FileIO::FileIO(const std::string& file)
    : game(file, std::ios::out | std::ios::in | std::ios::binary){
        //validate the game file
    if(!game){
        std::cerr << "no valid file!" << std::endl;
    }

    
}

FileIO::~FileIO(){
    if(game){
        game.close();
    }
}

void FileIO::writeToFile(long offsetToWrite, uint16_t offset){
    game.seekp(offsetToWrite);
    game.write(reinterpret_cast<const char*>(&offset), sizeof(offset)); 
}


long* FileIO::readByte(long byteToRead, int amount){
    long bytes[amount];
    for(int i = 0; i < amount; i++){
        game.seekg(byteToRead + (amount * 8));
    }
    return bytes;
}
