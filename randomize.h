#pragma once

#include <cstdint>
#include <random>
#include <chrono>
#include <vector>
#include "pokemon.h"

class FileIO;
uint16_t getRandomPokemon();
std::vector<Pokemon> randomizeStarters(FileIO& game);
uint16_t getRandomNumber(int low, int high); //probably temporary