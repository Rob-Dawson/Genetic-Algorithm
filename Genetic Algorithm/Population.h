#pragma once
#include "DNA.h"
#include <vector>
#include <string>
using namespace std;
class Population
{
public:
	Population(std::string target, float &mutation, int &populationMax);
	void calcFitness();
	void selection();
	int acceptReject(float maxFitness);
	~Population();

	float mutationRate;
	string target;
	int generations;
	bool finished;
	int perfectScore;
	float maxFitness;
	string getBest();
	bool isFinished();
	int bestIndex;
	vector<DNA> population;
	vector<DNA> matingPool;
};

