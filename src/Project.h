#pragma once

#include "Settings.h"
#include "Document.h"
#include <vector>

class Project
{
public:
	
	Project(std::string path, const std::vector<std::string>& address);
	
protected:

private:
	
	std::string m_path;
	
	std::vector<Document> m_documents;
};