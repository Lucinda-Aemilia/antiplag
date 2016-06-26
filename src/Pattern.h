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
    Pattern(std::string pattern, int pos, int id = 0, int documentId = 0, int projectId = 0);
	
	/// operator < for inserting into PatternTree
	bool operator < (const Pattern& right)
	{
		return m_pattern < right.m_pattern;
	}
	
    /// \return The hash value.
	long long int getHash() const { return m_hash; }
	
    /// \return the length of the pattern.
	int getLength() const { return m_pattern.length(); }

    /// \return The position of the pattern in its document.
    int getPos() const { return m_pos; }
	
	std::string getPattern() const { return m_pattern; }
	
	/// print basic information about the pattern
	void print() const;

    int getProjectId() const { return m_projectId; }

    int getDocumentId() const { return m_documentId; }

    int getId() const { return m_id; }

protected:
	void calcHash();
	
private:
	// Pattern(const Pattern& other);
	Pattern& operator = (const Pattern& other);
	
	std::string m_pattern;
	int m_pos;
	long long int m_hash;

    int m_id;
    int m_documentId;
    int m_projectId;
};
