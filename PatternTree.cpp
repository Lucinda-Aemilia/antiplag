#include "PatternTree.h"
#include <vector>
#include <iostream>

PatternTree* PatternTree::m_instance = NULL;

PatternTree::PatternTree()
{
	#ifdef DEBUG
	debugout << "Constructing an instance of PatternTree" << std::endl;
	#endif // DEBUG
}

PatternTree* PatternTree::instance()
{
	if (m_instance == NULL)
		m_instance = new PatternTree();
	return m_instance;
}

void PatternTree::insert(const Pattern& pattern)
{
	m_tree.insert(std::pair<long long int, Pattern>(pattern.getHash(), pattern));
}

std::vector<Pattern> PatternTree::find(long long int hash)
{
	std::vector<Pattern> patternList;
	std::pair<patternMmap::iterator, patternMmap::iterator> p = m_tree.equal_range(hash);
	patternMmap::iterator i;
	for (i = p.first; i != p.second; i++)
	{
		patternList.push_back(i->second);
	}
	return patternList;
}

std::vector<Pattern> PatternTree::getAll()
{
	std::vector<Pattern> patternList;
	patternMmap::iterator i;
	for (i = m_tree.begin(); i != m_tree.end(); i++)
		patternList.push_back(i->second);
	return patternList;
}

void PatternTree::print()
{
	#ifdef DEBUG
	debugout << "Number of patterns in the tree: " << m_tree.size() << std::endl;
	#endif // DEBUG
}

void PatternTree::destroy()
{
	if (m_instance != NULL) delete m_instance;
	m_instance = NULL;
	
	#ifdef DEBUG
	debugout << "Destroying the instance of PatternTree" << std::endl;
	#endif // DEBUG
}