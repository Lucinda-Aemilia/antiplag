#include "Project.h"

/// Note: need to think about reference here
Project::Project(std::string path, const std::vector<std::string>& address) : m_path(path)
{
	for (int i = address.size() - 1; i >= 0; i--)
		m_documents.push_back(Document(address[i]));
}