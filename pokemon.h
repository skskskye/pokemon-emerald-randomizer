#include <string>
#include <iostream>

class Pokemon
{
    private: 
        int hex[1];
        int minLevel;
        int maxLevel;
    public:
        Pokemon(char* name, int min, int max);
        int getMinLevel();
        int getMaxLevel();
        int* getHex();
};