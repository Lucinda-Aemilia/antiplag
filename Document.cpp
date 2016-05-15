#include "Document.h"
#include "Settings.h"
#include "PatternTree.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

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
	std::cout << "File path: " << m_address << std::endl;
	/*
	for (int i = 0; i < patternList.size(); i++)
		patternList[i].print();
	*/
	#endif //DEBUG
	
	for (int i = 0; i < patternList.size(); i++)
	{
		#ifdef DEBUG
		std::cout << "Checking Pattern: " << std::endl << "  ";
		patternList[i].print();
		std::cout << "  Parent file: " << patternList[i].getParDocument()->getAddress() << std::endl;
		#endif // DEBUG
		
		int length = patternList[i].getLength();
		if (length > m_content.length()) continue;
		
		long long int hash = 0, pow = 1;
		for (int j = length-1; j >= 0; j--)
		{
			hash += (int)m_content[j] * pow;
			if (j != 0)
				pow *= RK_BASE;
			hash %= RK_MOD;
			pow %= RK_MOD;
		}
		for (int j = 0; j < m_content.length()-length; j++)
		{
			if (hash == patternList[i].getHash())
			{
				#ifdef DEBUG
				std::cout << "  *Detected pattern in this document" << std::endl;
				std::cout << "    position: " << j << std::endl;
				#endif // DEBUG
			}
			hash -= (int)m_content[j] * pow;
			hash *= RK_BASE;
			hash += (int)m_content[j + length];
			hash %= RK_MOD;
			hash = (hash + RK_MOD) % RK_MOD;
		}
	}
}

/// Perdorm KMP algorithm for this document.
void Document::KMP()
{
	std::vector<Pattern> patternList(PatternTree::instance()->getAll());
	
	#ifdef DEBUG
	std::cout << std::endl << "********************************************************************************\n" << std::endl;
	std::cout << "KMP algorithm" << std::endl;
	std::cout << "File path: " << m_address << std::endl;
	#endif //DEBUG
	
	for (int i = 0; i < patternList.size(); i++)
	{
		#ifdef DEBUG
		std::cout << "Checking Pattern: " << std::endl << "  ";
		patternList[i].print();
		std::cout << "  Parent file: " << patternList[i].getParDocument()->getAddress() << std::endl;
		#endif // DEBUG
		
		std::string pattern(patternList[i].getPattern());
		int length = pattern.length();
		// std::vector<int> next(length, 0);
		
		char* str = new char[m_content.length()];
		strcpy(str, m_content.c_str());
		// std::cout << str << std::endl;
		int last = 0;
		while (last < m_content.length())
		{
			char* occ = strstr(str + last, pattern.c_str());
			if (occ == NULL) break;
			else
			{
				#ifdef DEBUG
				std::cout << "  *Detected pattern in this document" << std::endl;
				std::cout << "    position: " << (int)(occ - str) << std::endl;
				#endif // DEBUG
				last = occ - str + 1;
			}
		}
		delete str;
	}		
}