#include "Document.h"
#include "Settings.h"
#include "PatternTree.h"
#include <fstream>
#include <iostream>
#include <vector>

Document::Document(std::string address) : m_address(address)
{
	std::ifstream fin(address.c_str());
	// std::cout << address << std::endl;
	
	// still need to handle exception here
	try
	{
		if (!fin.is_open()) throw 0;
	}
	catch (int)
	{
		std::cerr << "No open file" << std::endl;
	}
	
	std::string curLine;
	while (std::getline(fin, curLine))
	{
		m_content.append(curLine);
		m_content += '\n';
	}
	
	#ifdef DEBUG
	std::cout << std::endl << "********************************************************************************\n" << std::endl;
	std::cout << "Document address: " << m_address << std::endl << std::endl;
	// std::cout << "Content before prepossing" << std::endl << m_content << std::endl;
	#endif // DEBUG
	
	preprocess();
	
	#ifdef DEBUG
	// std::cout << "Content after preprocessing:" << std::endl << m_content << std::endl << std::endl;
	#endif // DEBUG
	
	makePattern();
	
	#ifdef DEBUG
	std::cout << "Patterns made:" << std::endl;
	for (int i = 0; i < m_patterns.size(); i++)
		m_patterns[i].print();
	std::cout << std::endl;
	#endif // DEBUG
	
	for (int i = 0; i < m_patterns.size(); i++)
		PatternTree::instance()->insert(m_patterns[i]);
	#ifdef DEBUG
	PatternTree::instance()->print();
	#endif // DEBUG
	
	fin.close();
}

void Document::makePattern()
{
	// algorithm: ramdomly choose 10-20 patterns, each with length 10-20
	int count_pattern = randWithRange(10, 20);
	for (int i = 0; i < count_pattern; i++)
	{
		int length = randWithRange(10, 20);
		int pos = randWithRange(0, m_content.length());
		if (pos + length >= m_content.length()) length = m_content.length() - pos;
		m_patterns.push_back(Pattern((*this), m_content.substr(pos, length), pos));
	}
}

/// Remove spaces and taps and etc;
/// Need to replace comments
/// Need to add replacement
void Document::preprocess()
{
	std::string newContent;
	for (int i = 0; i < m_content.length(); i++)
	{
		if (isValid(m_content[i]))
			newContent += m_content[i];
	}
	m_content = newContent;
}

bool Document::isValid(char c)
{
	if (c>=33 && c<=126) return true;
	return false;
}

/// Perform Rabin-Karp algorithm for this document.
void Document::RabinKarp()
{
	std::vector<Pattern> patternList(PatternTree::instance()->getAll());
	
	#ifdef DEBUG
	std::cout << std::endl << "********************************************************************************\n" << std::endl;
	std::cout << "Rabin-Karp algorithm" << std::endl;
	for (int i = 0; i < patternList.size(); i++)
		patternList[i].print();
	#endif //DEBUG
	
	
}

/// Perdorm KMP algorithm for this document.
void Document::KMP()
{
	
}