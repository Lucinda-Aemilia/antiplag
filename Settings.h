#pragma once

#include <random>
#include <map>
#include <string>
#include <ostream>
#include <sstream>

/// If DEBUG is defined, then log is printed, either via std::cout
/// or into log.txt.
#define DEBUG

/// If DEBUG_LOGFILE is defined, then log is printed into log.txt.
/// Otherwise, log is printed via std::cout.
/// If DEBUG is disabled, then this macro is useless. 
#define DEBUG_LOGFILE

/// @return a random value in [lo, hi].
/// Uses std::default_random_engine.
/// Coding skill: static member
extern int randWithRange(int lo, int hi);

extern const int RK_MOD;

extern const int RK_BASE;

/// For debug output
/// Note: the std::ofstream debugout is giving me tens of thousands of errors!!!
/// Note: I will encapsulate the log facilities tomorrow. Now I will just disable DEBUG_LOGFILE.
/// Note: I use stringstream for log now. Just output the stringstream in cleanUp().
#ifdef DEBUG
	#ifdef DEBUG_LOGFILE
	extern std::stringstream debugout;
	#else
	extern std::ostream& debugout;
	#endif // DEBUG_LOGFILE
#endif // DEBUG

/// Types of documents that can be handled, i.e. ".cpp"
extern const std::string TYPE[];

/// Size of TYPE.
extern const int TYPE_COUNT;
