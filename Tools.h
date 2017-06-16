#include <string>
#include <sstream>
#include <iostream>

std::string CheckName(int length, std::string& FullName,  bool justname);

template <typename T> std::stringstream NumberToString(T Numb)
{
	std::stringstream str;
	str << Numb;
	return str;
}