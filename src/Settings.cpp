#include "Settings.h"

#include <random>
#include <ctime>

int randWithRange(int lo, int hi)
{
	static std::default_random_engine rd(time(0));
	// Still need to think about handling exception here 
	if (lo > hi)
		std::swap(lo, hi);
	return rd() % (hi+1-lo) + lo;
}

extern const int RK_MOD = 1e6 + 7;
extern const int RK_BASE = 97;

/// The length of the window for winnowing algorithm, or the *guarantee threshold*.
extern const int WINDOW_LENGTH = 500;

/// The length of the patterns used by winnowing algorithm, or the *noise threshold*.
extern const int PATTERN_LENGTH = 50;

extern const std::string TYPE[] = {".cc", ".cpp", ".cxx", ".h"};
extern const int TYPE_COUNT = 4;

