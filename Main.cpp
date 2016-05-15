#include "antiplag.h"

#include <iostream>

int main()
{
	Document doc1("testcase\\any.cc");
	Document doc2("testcase\\map_field.cc");
	Document doc3("testcase\\service.cc");
	
	doc1.RabinKarp();
	
	PatternTree::instance()->destroy();
	// Seems we cannot call that
	return 0;
}