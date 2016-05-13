#include "antiplag.h"
#include <iostream>

int main(int argc, char** argv)
{
	#ifdef DEBUG
	
	std::cout << "Arguments: " << argc << std::endl;
	
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}
	
	#endif // DEBUG
	
	// let argv[1] be the path
	
	FileManagement f;
	f.findSingle("testcase");
	// C:\\Users\\lenovo\\Documents\\OOP_programming\\Team_Project\\testcase
	
	return 0;
}