#pragma once

#include "Settings.h"
#include "Pattern.h"

#include <string>
#include <vector>

class Document
{
public:

    struct Resemblance
    {
        int m_projectId;
        int m_other_projectId;

        int m_documentId;
        int m_other_documentId;

        int m_pos;
        int m_other_pos;

        Resemblance(int projectId, int other_projectId, int documentId, int other_documentId,
                    int pos, int other_pos) :
            m_projectId(projectId), m_other_projectId(other_projectId), m_documentId(documentId),
            m_other_documentId(other_documentId), m_pos(pos), m_other_pos(other_pos)
        {
            swap();
        }

        void swap()
        {
            if (m_projectId > m_other_projectId)
            {
                std::swap(m_projectId, m_other_projectId);
                std::swap(m_documentId, m_other_documentId);
                std::swap(m_pos, m_other_pos);
            }
        }

        bool operator == (const Resemblance& other)
        {
            return m_documentId==other.m_documentId && m_other_documentId==other.m_other_documentId
                    && m_other_pos==other.m_other_pos && m_other_projectId==other.m_other_projectId
                    && m_pos==other.m_pos && m_projectId==other.m_projectId;
        }

        bool operator < (const Resemblance& other)
        {
            if (m_projectId != other.m_projectId)
                return m_projectId < other.m_projectId;

            if (m_other_projectId != other.m_other_projectId)
                return m_other_projectId < other.m_other_projectId;

            return false;
        }

        void print()
        {
            std::cout << "= Position in " << m_projectId << '.' << m_documentId << " document: " << m_pos << std::endl;
            std::cout << "= Position in " << m_other_projectId << '.'
                      << m_other_documentId << " the other document: " << m_other_pos << std::endl;
        }
    };
	
    Document(std::string address, int id = 0, int projectId = 0);

    std::vector<Resemblance> Winnowing();
	
	void RabinKarp();
	
	void KMP();
	
    std::string getAddress() const { return m_address; }

    int getId() const { return m_id; }

    int getProjectId() const { return m_projectId; }

    void print() const
    {
        std::cout << "Document: ";
        std::cout << m_address << std::endl;
    }

protected:

	void makePattern();
	
	void preprocess();
	
	bool isValid(char c);

    std::vector<Resemblance> m_resem;
	
private:

	// Document(const Document& other);
	Document& operator = (const Document& other);
	
	std::string m_address;
    int m_id;
    int m_projectId;
	std::string m_content;
	std::vector<Pattern> m_patterns;
};
