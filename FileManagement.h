#include "Settings.h"
#include <iostream>
#include <io.h>

class Document;
class Project;

class FileManagement
{
public:
	bool findSingle(std::string filePath)
	{
		filePath += "\\*.cpp";
		std::cout << filePath << std::endl;
		
		_finddata_t fileInfo;
		long handle = _findfirst(filePath.c_str(), &fileInfo);
		int n = 0;

		if (handle == -1L)
		{
			std::cerr << "failed to transfer files" << std::endl;
			return false;
		}

		do 
		{
			n++;
			std::cout << fileInfo.name << std::endl;
		} while (_findnext(handle, &fileInfo) == 0);
		
		std::cout << " .cpp files' number:  " << n << std::endl;
		_findclose(handle);

		return true;
	}
	
private:
	
};