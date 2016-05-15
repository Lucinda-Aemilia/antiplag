#include "antiplag.h"

#include <iostream>
#include <ctime>

int main()
{
	Document doc1("testcase\\any.cc");
	Document doc2("testcase\\map_field.cc");
	Document doc3("testcase\\service.cc");
	
	int t1 = clock();
	
	for (int i = 0; i < 100; i++)
	{
		doc1.RabinKarp();
		doc2.RabinKarp();
		doc3.RabinKarp();
	}
	
	std::cout << "Rabin-Karp: " << clock() - t1 << std::endl;
	
	int t2 = clock();
	
	for (int i = 0; i < 100; i++)
	{
		doc1.KMP();
		doc2.KMP();
		doc3.KMP();
	}
	
	std::cout << "KMP: " << clock() - t2 << std::endl;
	
	// KMP is much faster than Rabin-Karp
	
	PatternTree::instance()->destroy();
	// Seems we cannot call that
	return 0;
}