#pragma once

#include "Settings.h"
#include "Project.h"
#include "PatternTree.h"
#include "Preprocess.h"
#include <iostream>
#include <string>
#include <vector>

class Homework
{
public:
	
	enum HomeworkType { Single, Multiple };
	
    Homework(std::string path, HomeworkType type, std::string excluded,
             Preprocess* preprocess = new SimplePreprocess());

    std::vector<std::vector<int>> getResult() { return m_clashes; }

    bool printToFile(std::string file = "result.txt");

protected:
		
	bool findSingle(std::string filePath);
	
	bool findMultiple(std::string filePath);
	
	void dfsFolder(std::string folderPath, std::vector<std::string>& address);

private:
	
	HomeworkType m_type;
	
	std::string m_path;
	
	std::vector<Project> m_projects;

    std::vector<Document::Resemblance> m_resems;

    std::vector<std::vector<int>> m_clashes;

    std::string m_excluded;

    Preprocess* m_preprocess;
};
