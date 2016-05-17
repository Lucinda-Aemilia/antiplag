#include "Homework.h"
#include <io.h>
#include <string>
#include <vector>
#include <string.h>

/// Initialization and build the whole file system
Homework::Homework(std::string path, HomeworkType type) : m_path(path), m_type(type)
{
	if (type == Single)
	{
		if (!findSingle(path))
			throw "Can't find the path " + path;
	}
	else
	{
		if (!findMultiple(path))
			throw "Can't find the path " + path;
	}
}

bool Homework::findSingle(std::string filePath)
{
	std::string find;
	
	#ifdef DEBUG
	debugout << "\n********************************************************************************\n\n" ;
	debugout << "Single file mode: " << std::endl;
	debugout << "Searching for path: " << filePath << std::endl;
	#endif // DEBUG
	
	_finddata_t fileInfo;
	std::string newPath = filePath + "\\*.*";
	long handle = _findfirst(newPath.c_str(), &fileInfo);

	if (handle == -1L)
	{
		// how to handle exception here
		std::cerr << "failed to open files" << std::endl;
		return false;
	}
	
	std::vector<std::string> address(1, "");
	std::string name;
	do 
	{
		name = fileInfo.name;
		
		bool find = false;
		for (int i = 0; i < TYPE_COUNT; i++)
		{
			if (name.length() >= TYPE[i].length() && name.substr(name.length() - TYPE[i].length(), name.length()) == TYPE[i])
			{
				find = true;
				break;
			}
		}
		if (!find)
			continue;
		
		address[0] = filePath + "\\" + name;
		
		#ifdef DEBUG
		debugout << "\n********************************************************************************\n\n" ;
		debugout << "Processing: " << fileInfo.name << std::endl;
		debugout << "Address = " << address[0] << std::endl;
		#endif // DEBUG
		
		m_projects.push_back(Project(filePath, address));
		
	} while (_findnext(handle, &fileInfo) == 0);		
	
	_findclose(handle);

	return true;
}


bool Homework::findMultiple(std::string filePath)
{
	_finddata_t fileInfo;
    std::string strfind = filePath + "\\*";
    long Handle = _findfirst(strfind.c_str(), &fileInfo);
    
    if (Handle == -1L)
    {
        std::cerr << "Cannot match the folder path" << std::endl;
        return false;
    }
	
	std::vector<std::string> address;
	
	do {
        if (fileInfo.attrib & _A_SUBDIR)    
        {
            if ( (strcmp(fileInfo.name,".") != 0 ) && (strcmp(fileInfo.name,"..") != 0))   
            {
				address.clear();
                std::string projectPath = filePath + "\\" + fileInfo.name;
                dfsFolder(projectPath, address);
				m_projects.push_back(Project(projectPath, address));
            }
        }
    } while (_findnext(Handle, &fileInfo) == 0);

    _findclose(Handle);
	
	return true;
}

void Homework::dfsFolder(std::string folderPath, std::vector<std::string>& address)
{
    _finddata_t fileInfo;
    std::string strfind = folderPath + "\\*";
    long Handle = _findfirst(strfind.c_str(), &fileInfo);
    
    if (Handle == -1L)
    {
        std::cerr << "can not match the folder path" << std::endl;
        return;
    }
    do {
        if (fileInfo.attrib & _A_SUBDIR)    
        {
            if ((strcmp(fileInfo.name, ".") != 0 ) && (strcmp(fileInfo.name, "..") != 0))   
            {
                std::string newPath = folderPath + "\\" + fileInfo.name;
                dfsFolder(newPath, address);
            }
        }
        else  
			address.push_back(folderPath + "\\" + fileInfo.name);
            
    } while (_findnext(Handle, &fileInfo) == 0);

    _findclose(Handle);
	return;
}
