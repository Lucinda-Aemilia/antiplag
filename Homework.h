#pragma once

#include "Settings.h"
#include "Project.h"
#include <iostream>
#include <string>
#include <vector>

class Homework
{
public:
	
	enum HomeworkType { Single, Multiple };
	
	Homework(std::string path, HomeworkType type);

protected:
		
	bool findSingle(std::string filePath);
	
	bool findMultiple(std::string filePath);
	
	void dfsFolder(std::string folderPath, std::vector<std::string>& address);

private:
	
	HomeworkType m_type;
	
	std::string m_path;
	
	std::vector<Project> m_projects;
};