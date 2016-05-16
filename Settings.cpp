#include "Settings.h"

#include <random>
#include <ctime>

int randWithRange(int lo, int hi)
{
	static std::default_random_engine rd(time(0));
	return rd() % (hi+1-lo) + lo;
}

extern const int RK_MOD = 1e6 + 7;
extern const int RK_BASE = 97;

extern const std::string TYPE[] = {".cc", ".cpp", ".cxx", ".h"};
extern const int TYPE_COUNT = 4;