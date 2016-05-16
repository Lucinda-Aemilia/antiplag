#include "antiplag.h"

#include <iostream>
#include <fstream>
#include <ctime>

void Initialize()
{
	// For cleaning up the contents in log.txt
	std::ofstream logout("log.txt");
	logout.close();
}

void cleanUp()
{
	PatternTree::instance()->destroy();
	
	#ifdef DEBUG
	debugout << "Finishing up this program" << std::endl;
	#endif // DEBUG
	
	#ifdef DEBUG
		#ifdef DEBUG_LOGFILE
		// debugout.close();
		#endif // DEBUG_LOGFILE
	#endif // DEBUG
}

#ifdef DEBUG
	#ifdef DEBUG_LOGFILE
	std::ofstream debugout;
	debugout.open("log.txt", std::ios::out);
	// debugout.open("log.txt", std::ios::out);
	#else
	std::ostream& debugout = std::cout;
	#endif // DEBUG_LOGFILE
#endif // DEBUG
	
int main()
{
	Initialize();
	
	Homework hw1("testcase", Homework::Single);
	Homework hw2("testcase", Homework::Multiple);
	
	cleanUp();
	
	return 0;
}