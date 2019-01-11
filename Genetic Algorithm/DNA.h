#pragma once
#include <string>
#include <vector>
using namespace std;

class DNA
{
public:
	DNA(int num);
	DNA* crossover(DNA &partner) ;
	string getPhrase();
	float fitness(string target);
	vector<char>genes;
	void mutate(float mutationRate);
	float fit;
	DNA *child;
	~DNA();
};

