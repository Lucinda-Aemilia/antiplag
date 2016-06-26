#pragma once

#include "Settings.h"
#include "Document.h"
#include <vector>

class Project
{
public:
	
    Project(std::string path, const std::vector<std::string>& address, int id = 0);

    std::vector<Document::Resemblance> doWinnow();

    int getId() const { return m_id; }

protected:

private:
	
	std::string m_path;
	
	std::vector<Document> m_documents;

    std::vector<Document::Resemblance> m_resem;

    int m_id; ///< The index in the Homework object.
};
