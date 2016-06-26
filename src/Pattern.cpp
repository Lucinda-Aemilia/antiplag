#include "Pattern.h"

// Pattern::Pattern() : m_pattern(""), m_parDocument(NULL) {}

Pattern::Pattern(std::string pattern, int pos, int id/* = 0 */, int documentId/* = 0 */,
                 int projectId/* = 0 */):
  m_pattern(pattern), m_pos(pos), m_hash(0), m_id(id), m_documentId(documentId), m_projectId(projectId)
{
	calcHash();
}
  
void Pattern::print() const
{
    std::cout << "Project ID: " << m_projectId << " Document Id: " << m_documentId << std::endl;
	std::cout << "Position=" << m_pos << " Hash=" << m_hash <<  " Content=" << m_pattern << std::endl;
}

void Pattern::calcHash()
{
	m_hash = 0;
	long long int pow = 1;
	for (int i = m_pattern.length()-1; i >= 0; i--)
	{
		m_hash += pow * (int)m_pattern[i];
		pow *= RK_BASE;
		m_hash %= RK_MOD;
		pow %= RK_MOD;
	}
}
