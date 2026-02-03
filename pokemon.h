#include <string>
#include <iostream>
#include <cstdint>

class Pokemon
{
    private: 
        std::string name; //dont know if i will have this included
        u_int16_t hex;
        int minLevel;
        int maxLevel;
    public:
        Pokemon(uint16_t hex ,std::string name, int min, int max);
        int getMinLevel();
        int getMaxLevel();
        uint16_t getHex();
};