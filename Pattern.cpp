#include "Pattern.h"

// Pattern::Pattern() : m_pattern(""), m_parDocument(NULL) {}

Pattern::Pattern(Document& parDocument, std::string pattern, int pos): 
  m_parDocument(&parDocument), m_pattern(pattern), m_pos(pos), m_hash(0)
{
	calcHash();
}
  
void Pattern::print() const
{
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