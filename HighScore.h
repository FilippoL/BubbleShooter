#pragma once
#include "FileManager.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

class HighScore
{
public:
	HighScore();
	~HighScore();
	void Initialise(std::string section);
	void Reset();
	void UpdateHighscore(float s);
	std::vector<float> GetHighscore();

	int score;
	FileManager _highscore_path;
	std::string _highscore;
	std::vector<float>  _hg;

};

