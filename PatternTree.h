#pragma once

#include "Settings.h"
#include "Pattern.h"
#include <map>
#include <algorithm>

typedef std::multimap<long long int, Pattern> patternMmap;

/// A tree with all patterns stored in it
/// Singleton
class PatternTree
{
public:
	
	PatternTree();
	
	static PatternTree* instance();
	
	void destroy();
	
	/// insert a pattern into the tree
	void insert(const Pattern& pattern);
	
	/// find a set of patterns with the same hash value in the tree
	/// Note: I cannot make it const...
	std::vector<Pattern> find(const long long int hash);
	
	std::vector<Pattern> getAll();
	
	/// print some basic information about the tree
	void print();
	
private:

	patternMmap m_tree;
	
	static PatternTree* m_instance;
	PatternTree(const PatternTree& other);
	PatternTree& operator = (const PatternTree& right);
};
