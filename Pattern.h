#pragma once

#include <string>
#include <iostream>
#include "Settings.h"

class Document;

/// Storing patterns from a document
class Pattern
{
public:
	
	/// The only constructor
	Pattern(Document& parDocument, std::string pattern, int pos);
	
	/// operator < for inserting into PatternTree
	bool operator < (const Pattern& right)
	{
		return m_pattern < right.m_pattern;
	}
	
	/// @return The hash value.
	long long int getHash() const { return m_hash; }
	
	/// @return the length of the pattern.
	int getLength() const { return m_pattern.length(); }
	
	/// @return the address of the parent document.
	/// Note: need to use const here
	Document* getParDocument() { return m_parDocument; }
	
	std::string getPattern() const { return m_pattern; }
	
	/// print basic information about the pattern
	void print() const;

protected:
	void calcHash();
	
private:
	// Pattern(const Pattern& other);
	Pattern& operator = (const Pattern& other);
	
	std::string m_pattern;
	int m_pos;
	long long int m_hash;
	Document* m_parDocument;
};