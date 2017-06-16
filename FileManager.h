#pragma once
#include <map>
#include <fstream>


class FileManager
{
public:
	FileManager();

	void InitialiseSection(std::string sec);


	std::string GetAlphabeticVariable(const std::string &VarName);

	float GetNumericVariable(std::string VarName);


	~FileManager();


private:

	void ReadFromFile();

	void RemoveSpaces(std::string & givemeastring);

	std::string filename;

	std::fstream file;

	
	std::map<std::string, std::string> _variables_map;


	std::string _section;

};

