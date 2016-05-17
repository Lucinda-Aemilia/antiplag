#include "antiplag.h"

#include <iostream>
#include <fstream>
#include <ctime>

int ans = 1;

void Initialize()
{
	// Initialize RK_BASE_POW
	for (int i = 1; i < PATTERN_LENGTH; i++)
	{
		ans *= RK_BASE;
		ans %= RK_MOD;
	}
	
	// For cleaning up the contents in log.txt
	std::ofstream logout("log.txt");
	logout.close();
}

extern const int RK_BASE_POW = ans;

void cleanUp()
{
	PatternTree::instance()->destroy();
	
	#ifdef DEBUG
	debugout << "Finishing up this program" << std::endl;
	#endif // DEBUG
	
	#ifdef DEBUG
		#ifdef DEBUG_LOGFILE
		// debugout.close();
		std::ofstream logout("log.txt");
		logout << debugout.str() << std::endl;
		logout.close();
		#endif // DEBUG_LOGFILE
	#endif // DEBUG
}

#ifdef DEBUG
	#ifdef DEBUG_LOGFILE
	// std::ofstream debugout;
	// debugout.open("log.txt", std::ios::out);
	// debugout.open("log.txt", std::ios::out);
	std::stringstream debugout;
	#else
	std::ostream& debugout = std::cout;
	#endif // DEBUG_LOGFILE
#endif // DEBUG
	
int main()
{
	Initialize();
	
	Homework hw1("..\\testcase", Homework::Single);
	Homework hw2("..\\testcase", Homework::Multiple);
	
	cleanUp();
	
	return 0;
}