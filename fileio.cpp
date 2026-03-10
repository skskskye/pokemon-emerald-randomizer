#include "fileio.h"
#include <cstdint>
#include <iostream>

const std::string TITLE = "POKEMON EMER"; //TITLE
uint32_t titleOffset = 0x000000A0; //this is where the game title is

FileIO::FileIO(const std::string& file)
    : game(file, std::ios::out | std::ios::in | std::ios::binary){
        //validate the game file
    if(!game){
        std::cerr << "no valid file!" << std::endl;
    }else{
        std::cout << "found game file!" << std::endl;
    }
    
    //check if the game is a "real game"
    uint8_t* bytes = readByte(titleOffset, 12); 

    //converting 
    std::string byteToString(reinterpret_cast<const char*>(bytes));

    if(byteToString != TITLE){
        std::cout << byteToString << std::endl;
        std::cout << TITLE << std::endl;
        std::cerr << "Wrong game!!" << std::endl;
    }else{
        std::cout << "correct game!... randomizing" << std::endl;
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


uint8_t* FileIO::readByte(uint32_t byteToRead, int amount){
    uint8_t* bytes = new uint8_t[amount];
    game.seekg(byteToRead);
    
    
    game.read(reinterpret_cast<char*>(bytes), amount);
    return bytes;
}

