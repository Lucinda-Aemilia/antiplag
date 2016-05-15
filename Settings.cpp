#include "Settings.h"

#include <random>
#include <ctime>

int randWithRange(int lo, int hi)
{
	static std::default_random_engine rd(time(0));
	return rd() % (hi+1-lo) + lo;
}