#pragma once

#include <random>
#include <map>
#include <string>
#include <ostream>

#define DEBUG

extern int randWithRange(int lo, int hi);

extern const int RK_MOD;

extern const int RK_BASE;

/// Note: to realize output here; a singleton of ofstream object
// std::ofstream apout("log.txt");

extern const std::string TYPE[];

extern const int TYPE_COUNT;