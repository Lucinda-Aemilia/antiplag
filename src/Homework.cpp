#include "Homework.h"
#include <io.h>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <QDebug>

/// Initialization and build the whole file system
Homework::Homework(std::string path, HomeworkType type, std::string excluded,
                   Preprocess* preprocess/* = new SimplePreprocess()*/) : m_path(path),
    m_type(type), m_excluded(excluded), m_preprocess(preprocess)
{
    PatternTree::instance()->clearAll();

	if (type == Single)
	{
		if (!findSingle(path))
			throw "Can't find the path " + path;
	}
	else
	{
		if (!findMultiple(path))
			throw "Can't find the path " + path;
	}

    // Preprocess the contents to be excluded
    m_preprocess->work(m_excluded);

    if (m_excluded.size() >= PATTERN_LENGTH)
    {
        // Delete the patterns that should be excluded
        long long int hash = 0, pow = 1;
        for (int j = PATTERN_LENGTH-1; j >= 0; j--)
        {
            hash += (int)m_excluded[j] * pow;
            if (j != 0)
                pow *= RK_BASE;
            hash %= RK_MOD;
            pow %= RK_MOD;
        }
        for (int j = 0; j < m_excluded.length()-PATTERN_LENGTH; j++)
        {
            PatternTree::instance()->erase(hash, m_excluded.substr(j, PATTERN_LENGTH));

            hash -= (int)m_excluded[j] * pow;
            hash *= RK_BASE;
            hash += (int)m_excluded[j + PATTERN_LENGTH];
            hash %= RK_MOD;
            hash = (hash + RK_MOD) % RK_MOD;
        }
    }

    m_resems.clear();
    for (int i = 0; i < m_projects.size(); i++)
    {
        std::vector<Document::Resemblance> resem(m_projects[i].doWinnow());
        m_resems.insert(m_resems.end(), resem.begin(), resem.end());
    }

    m_clashes.clear();
    for (int i = 0; i < m_projects.size(); i++)
        m_clashes.push_back(std::vector<int>(m_projects.size(), 0));

    std::sort(m_resems.begin(), m_resems.end());
    m_resems.erase(std::unique(m_resems.begin(), m_resems.end()), m_resems.end());

    for (int i = 0; i < m_resems.size(); i++)
    {
        m_clashes[m_resems[i].m_projectId][m_resems[i].m_other_projectId]++;
        m_clashes[m_resems[i].m_other_projectId][m_resems[i].m_projectId]++;
    }
}

bool Homework::findSingle(std::string filePath)
{
	std::string find;
	

    std::cout << "\n********************************SINGLE MODE*************************************\n\n" ; // SINGLE MODE
    std::cout << "Single file mode: " << std::endl;
    std::cout << "Searching for path: " << filePath << std::endl;

	
	_finddata_t fileInfo;
	std::string newPath = filePath + "\\*.*";
	long handle = _findfirst(newPath.c_str(), &fileInfo);

	if (handle == -1L)
	{
		// how to handle exception here
		std::cerr << "failed to open files" << std::endl;
		return false;
	}
	
	std::vector<std::string> address(1, "");
	std::string name;
	do 
	{
		name = fileInfo.name;
		
		bool find = false;
		for (int i = 0; i < TYPE_COUNT; i++)
		{
			if (name.length() >= TYPE[i].length() && name.substr(name.length() - TYPE[i].length(), name.length()) == TYPE[i])
			{
				find = true;
				break;
			}
		}
		if (!find)
			continue;
		
        address[0] = filePath + "\\" + name;
		

        std::cout << "\n********************************************************************************\n\n" ;
        std::cout << "Processing: " << fileInfo.name << std::endl;
        std::cout << "Address = " << address[0] << std::endl;

		
        m_projects.push_back(Project(address[0], address, m_projects.size()));
		
	} while (_findnext(handle, &fileInfo) == 0);		
	
	_findclose(handle);
	

    std::cout << "\n********************************SINGLE MODE END*********************************\n\n" ;

	
	return true;
}


bool Homework::findMultiple(std::string filePath)
{

    std::cout << "\n*********************MULTIPLE FILE MODE*****************************************\n\n" ;
    std::cout << "Multiple file mode: " << std::endl;
    std::cout << "Searching for path: " << filePath << std::endl;

	
	_finddata_t fileInfo;
    std::string strfind = filePath + "\\*";
    long Handle = _findfirst(strfind.c_str(), &fileInfo);
    
    if (Handle == -1L)
    {
        std::cerr << "Cannot match the folder path" << std::endl;
        return false;
    }
	
	std::vector<std::string> address;
	
	do {
        if (fileInfo.attrib & _A_SUBDIR)    
        {
            if ( (strcmp(fileInfo.name,".") != 0 ) && (strcmp(fileInfo.name,"..") != 0))   
            {
				address.clear();
                std::string projectPath = filePath + "\\" + fileInfo.name;

                std::cout << projectPath << endl;

                dfsFolder(projectPath, address);
                m_projects.push_back(Project(projectPath, address, m_projects.size()));
            }
        }
    } while (_findnext(Handle, &fileInfo) == 0);

    _findclose(Handle);
	

    std::cout << "\n*********************MULTIPLE FILE MODE END*************************************\n\n" ;

	
	return true;
}

void Homework::dfsFolder(std::string folderPath, std::vector<std::string>& address)
{
    _finddata_t fileInfo;
    std::string strfind = folderPath + "\\*";
    long Handle = _findfirst(strfind.c_str(), &fileInfo);
    
    if (Handle == -1L)
    {
        std::cerr << "can not match the folder path" << std::endl;
        return;
    }
    do {
        if (fileInfo.attrib & _A_SUBDIR)    
        {
            if ((strcmp(fileInfo.name, ".") != 0 ) && (strcmp(fileInfo.name, "..") != 0))   
            {
                std::string newPath = folderPath + "\\" + fileInfo.name;
                dfsFolder(newPath, address);
            }
        }
        else  
			address.push_back(folderPath + "\\" + fileInfo.name);
            
    } while (_findnext(Handle, &fileInfo) == 0);

    _findclose(Handle);
	return;
}

bool Homework::printToFile(std::string file/* = "result.txt"*/)
{
    std::ofstream fout(file.c_str());
    if (!fout.is_open())
        return false;
    for (int i = 0; i < m_projects.size(); i++)
    {
        fout << "--------------------------------------\n";
        fout << "Project " << i << std::endl;
        fout << "Address: " << m_path << std::endl;
        fout << "Clashes: " << std::endl;

        for (int j = 0; j < m_projects.size(); j++)
        {
            if (j == i) continue;
            fout << "With Project " << j << std::endl;
            fout << "Clashes: " << m_clashes[i][j] << std::endl;

            fout << "Similarity: " << (double)m_clashes[i][j] * PATTERN_LENGTH / m_projects[i].getLength()
                 << " / " << (double)m_clashes[i][j] * PATTERN_LENGTH / m_projects[j].getLength()
                 << std::endl;
        }
    }
    fout.close();
    return true;
}
