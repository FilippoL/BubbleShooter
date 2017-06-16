#include "FileManager.h"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


FileManager::FileManager()
{
	filename = "Settings.txt";

	file.open(filename, std::ios::in);
	if (!file)
	{
		file.open(filename, std::ios::out);
		file.close();
		file.open(filename, std::ios::in);
		if (file.bad())
			{
				std::cout << "File opening FAILED";
			}
	}
	file.close();
}

void FileManager::InitialiseSection(std::string sec)
{
	_section = sec;
	ReadFromFile();
}

void FileManager::ReadFromFile()
{
	bool found = false;

	file.open(filename, std::ios::in);

	while (file.good())
	{
		std::string line;
		std::getline(file, line);
		
		if (line.find("#") != std::string::npos && found)
		{
			found = false;
		}

		if (line.find("#" + _section) !=  std::string::npos)
		{
			found = true;
		}

		if (found && line.find("#") == std::string::npos)
		{	
			size_t index = 0;

			size_t _end = 0;

			index = line.find_first_of("=");

	

			(_end != std::string::npos) ? _end = line.find("///") : _end = line.size();
		
			std::string variable;
			std::string definition;

			variable = line.substr(0, index);
			RemoveSpaces(variable);

			definition = line.substr(index + 1, _end - index);
			RemoveSpaces(definition);

			_variables_map[variable] = definition;
				
		}	
		

	}

	file.close();
}

void FileManager::RemoveSpaces(std::string &givemeastring)
{
	 givemeastring.erase(remove_if(givemeastring.begin(), givemeastring.end(), isspace), givemeastring.end());
}

std::string FileManager::GetAlphabeticVariable(const std::string &VarName)
{
	std::string str = _variables_map[VarName];

	return _variables_map[VarName];
}


float FileManager::GetNumericVariable(std::string VarName)
{
	return std::stof(_variables_map[VarName]);
}

FileManager::~FileManager()
{
}
