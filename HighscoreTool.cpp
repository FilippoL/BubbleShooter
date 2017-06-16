#include <string>
#include <map>
#include <set>
#include <iostream>
#include <windows.h>
#include <time.h>

#define MAX_SCORE 100

void GenerateScore(int &n);
std::map <int, std::string> HighScores;
std::string name;
int score;
void BubbleSort(std::map <std::string, int> w);


int main()
{
	
	HighScores[87] = "Karsten";
	HighScores[57] = "John";
	HighScores[67] = "Andrew";
	HighScores[77] = "Erik";
	HighScores[47] = "Donald";
	HighScores[67] = "Homer";
	HighScores[77] = "Teresa";
	HighScores[47] = "Brandp";


	std::cout << "Write your name: \n>>";
	std::getline(std::cin, name);
	while (name == "")
	{
		std::cout << "Write a valid name: \n>>";
		std::getline(std::cin, name);
		
	}
	int index = 0;






	GenerateScore(score);
	
	HighScores[score] = name;

	
	for (auto it = HighScores.begin(); it != HighScores.end(); it++)
	{
		std::cout << it->first << "    " << it->second<< std::endl;
	}



	system("PAUSE");
	
	main();
	return 0;
}

void BubbleSort(std::map <std::string, int> w)
{
/*	int n,d;

  for (auto it = w.begin() ; it != w.end(); it++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1])  For decreasing order use < 
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
  */
}

void GenerateScore(int &_score)
{
	auto it = HighScores.begin();
	_score =  rand() + 40 % it->first;
}