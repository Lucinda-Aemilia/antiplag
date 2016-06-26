#include "Document.h"
#include "Settings.h"
#include "PatternTree.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <QDebug>

Document::Document(std::string address, int id/* = 0*/, int projectId/* = 0*/,
                   Preprocess* preprocess/* = new SimpleProcess() */) :
    m_address(address), m_id(id), m_projectId(projectId), m_preprocess(preprocess)
{
	std::ifstream fin(address.c_str());
    // std::std::cout << address << std::endl;
	
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
	

    std::cout << std::endl << "********************************************************************************\n" << std::endl;
    std::cout << "Document address: " << m_address << std::endl << std::endl;
    // std::std::cout << "Content before prepossing" << std::endl << m_content << std::endl;
	
    // Preprocess
    m_preprocess->work(m_content);
	
	makePattern();

    std::cout << "Patterns made:" << std::endl;
	for (int i = 0; i < m_patterns.size(); i++)
    {
		m_patterns[i].print();
        // std::cout << m_patterns[i].getParDocument()->getAddress() << std::endl;
    }
    std::cout << std::endl;

	
	for (int i = 0; i < m_patterns.size(); i++)
		PatternTree::instance()->insert(m_patterns[i]);
	

	PatternTree::instance()->print();

	
	fin.close();
}

/// Make the patterns with winnowing algorithm
void Document::makePattern()
{
	if (m_content.length() < PATTERN_LENGTH)
		return;
	// NOTE: maybe need to think twice here about the sentinel value
	int min_pos = 0; // the place where the minimal hash value lies
	int right_end = 0; // the right end of the window
	int global_right_pos = 0; // the position of the end of vurrent pattern in m_content
	int hashWindow[WINDOW_LENGTH];
	
	// Initialize the hashes to maximum.
	for (int i = 0; i < WINDOW_LENGTH; i++)
		hashWindow[i] = INT_MAX;
	
	// calculate the first hash value
	hashWindow[0] = 0;
	for (int i = 0; i < PATTERN_LENGTH; i++)
	{
		hashWindow[0] *= RK_BASE;
		hashWindow[0] += (int)m_content[i];
		hashWindow[0] %= RK_MOD;
	}
	global_right_pos = PATTERN_LENGTH;
	
	// NOTE: still need to think about whether to do that or not
	// calculates the next WINDOW_LENGTH-1 hash values
	// for (int i = 1; i < WINDOW_LENGTH && i < m_content.length(); i++)
		
	// Begin rolling the window
	while (global_right_pos < m_content.length())
	{
		global_right_pos++;
		int next_hash = hashWindow[right_end];
		// get the next hash value
		next_hash -= (int)m_content[global_right_pos - PATTERN_LENGTH] * RK_BASE_POW;
		next_hash = (next_hash * RK_BASE + (int)m_content[global_right_pos]) % RK_MOD;
		next_hash = (next_hash + RK_MOD) % RK_MOD;
		
		right_end = (right_end + 1) % WINDOW_LENGTH;
		hashWindow[right_end] = next_hash;
		
		if (min_pos == right_end)
		{
			// The previous minimum is no longer in this
			// window. Scan hashWindow leftward starting from r
			// for the rightmost minimal hash.
			for (int i = (right_end-1+WINDOW_LENGTH) % WINDOW_LENGTH;
			  i != right_end; i = (i-1+WINDOW_LENGTH) % WINDOW_LENGTH)
				if (hashWindow[i] < hashWindow[min_pos]) min_pos = i;
				
			// calculate the pattern and insert it ***
			// !!! Please check it carefully!
			int start_pos = (right_end - min_pos + WINDOW_LENGTH) % WINDOW_LENGTH;
			start_pos = global_right_pos - PATTERN_LENGTH -start_pos;
            m_patterns.push_back(Pattern(m_content.substr(start_pos, PATTERN_LENGTH), start_pos,
                                         m_patterns.size(), m_id, m_projectId));
		}
		else
		{
			// Otherwise, the previous minimum is still in
			// this window. Compare against the new value
			// and update min if necessary.
			if (hashWindow[right_end] <= hashWindow[min_pos])
			{
				min_pos = right_end;
				int start_pos = global_right_pos - PATTERN_LENGTH;
                m_patterns.push_back(Pattern(m_content.substr(start_pos, PATTERN_LENGTH), start_pos,
                                             m_patterns.size(), m_id, m_projectId));
			}
		}
	}
}

std::vector<Document::Resemblance> Document::Winnowing()
{
    m_resem.clear();
    if (m_content.size() < PATTERN_LENGTH)
        return m_resem;

    std::cout << std::endl << "********************************************************************************\n" << std::endl;
    std::cout << "Winnowing Detection algorithm" << std::endl;
    std::cout << "File path: " << m_address << std::endl;

    long long int hash = 0, pow = 1;
    for (int j = PATTERN_LENGTH-1; j >= 0; j--)
    {
        hash += (int)m_content[j] * pow;
        if (j != 0)
            pow *= RK_BASE;
        hash %= RK_MOD;
        pow %= RK_MOD;
    }
    for (int j = 0; j < m_content.length()-PATTERN_LENGTH; j++)
    {
        std::vector<Pattern> clashes(PatternTree::instance()->find(hash));
        for (int k = 0; k < clashes.size(); k++)
        {
            if (clashes[k].getProjectId() != m_projectId
                    && m_content.substr(j, PATTERN_LENGTH) == clashes[k].getPattern())
            {
                m_resem.push_back(Resemblance(m_projectId, clashes[k].getProjectId(), m_id,
                                              clashes[k].getDocumentId(), j, clashes[k].getPos()));

                std::cout << "Find resemblance: " << std::endl;
                m_resem.back().print();
            }
        }

        hash -= (int)m_content[j] * pow;
        hash *= RK_BASE;
        hash += (int)m_content[j + PATTERN_LENGTH];
        hash %= RK_MOD;
        hash = (hash + RK_MOD) % RK_MOD;
    }

    return m_resem;
}

/// Perform Rabin-Karp algorithm for this document.
void Document::RabinKarp()
{
	std::vector<Pattern> patternList(PatternTree::instance()->getAll());
	

    std::cout << std::endl << "********************************************************************************\n" << std::endl;
    std::cout << "Rabin-Karp algorithm" << std::endl;
    std::cout << "File path: " << m_address << std::endl;
	/*
	for (int i = 0; i < patternList.size(); i++)
		patternList[i].print();
	*/

	
	for (int i = 0; i < patternList.size(); i++)
	{

        std::cout << "Checking Pattern: " << std::endl << "  ";
		patternList[i].print();
        std::cout << "  Parent file: " << patternList[i].getDocumentId() << std::endl;

		
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

                std::cout << "  *Detected pattern in this document" << std::endl;
                std::cout << "    position: " << j << std::endl;

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
	

    std::cout << std::endl << "********************************************************************************\n" << std::endl;
    std::cout << "KMP algorithm" << std::endl;
    std::cout << "File path: " << m_address << std::endl;

	
	for (int i = 0; i < patternList.size(); i++)
	{

        std::cout << "Checking Pattern: " << std::endl << "  ";
		patternList[i].print();
        std::cout << "  Parent file: " << patternList[i].getDocumentId() << std::endl;

		
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

                std::cout << "  *Detected pattern in this document" << std::endl;
                std::cout << "    position: " << (int)(occ - str) << std::endl;

				last = occ - str + 1;
			}
		}
		delete str;
	}		
}
