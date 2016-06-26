#include "Project.h"

/// Note: need to think about reference here
Project::Project(std::string path, const std::vector<std::string>& address, int id/* = 0 */)
    : m_path(path), m_id(id)
{
    m_length = 0;
    for (int i = 0; i < address.size(); i++)
    {
        m_documents.push_back(Document(address[i], i, m_id));
        m_length += m_documents[i].getLength();
    }
}

std::vector<Document::Resemblance> Project::doWinnow()
{
    m_resem.clear();

    for (int i = 0; i < m_documents.size(); i++)
    {
        std::vector<Document::Resemblance> resem(m_documents[i].Winnowing());
        m_resem.insert(m_resem.end(), resem.begin(), resem.end());
    }

    return m_resem;
}
