#pragma once

#include "Settings.h"
#include "Pattern.h"

#include <string>
#include <vector>

class Document
{
public:
	
	Document(std::string address);
	
	void RabinKarp();
	
	void KMP();
	
	std::string getAddress() { return m_address; }

protected:

	void makePattern();
	
	void preprocess();
	
	bool isValid(char c);
	
private:

	// Document(const Document& other);
	Document& operator = (const Document& other);
	
	std::string m_address;
	std::string m_content;
	std::vector<Pattern> m_patterns;
};