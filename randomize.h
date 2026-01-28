#include <cstdint>
#include <random>
#include <chrono>

class FileIO;

void randomize_starters(FileIO& game); 
uint16_t getRandomNumber(int range); //probably temporary