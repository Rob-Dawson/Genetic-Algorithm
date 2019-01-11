#include "Population.h"
#include <string>
#include <map>
#include "DNA.h"

Population::Population(std::string target, float & mutation, int & populationMax)
	: target{ target }, mutationRate{ mutation }
{
	for (auto i = 0; i < populationMax; ++i)
	{
		population.push_back(DNA(target.length()));
	}
	calcFitness();
	finished = false;
	bestIndex = 0;
	generations = 0;
}

void Population::calcFitness()
{
	maxFitness = 0.0f;
	for (auto i = 0; i < population.size(); ++i)
	{
		float fitness = population.at(i).fitness(target);
		population.at(i).fit = fitness;
		if (population.at(i).fit > maxFitness)
		{
			maxFitness = population.at(i).fit;
			bestIndex = i;
		}
	}
 }

void Population::selection()
{
	vector<DNA> newPopulation;

	for (int i = 0; i < population.size(); ++i)
	{
		auto partnerAIndex = acceptReject(maxFitness);
		auto partnerBIndex = acceptReject(maxFitness);

		auto partnerA = population.at(partnerAIndex);
		auto partnerB = population.at(partnerBIndex);

		auto child = partnerA.crossover(partnerB);
		child->mutate(mutationRate);
		newPopulation.push_back (*child);
	}
	population = newPopulation;
	finished = isFinished();
}

int Population::acceptReject(float maxFitness)
{
	while (true)
	{
		auto index = rand() % population.size();
		auto partner = population.at(index);
 		float r = ((float)rand() / RAND_MAX) * maxFitness;
		if (r < partner.fit)
		{
			return index;
		}
	}
	
}

string Population::getBest()
{
	auto i = population.at(bestIndex);
	string phrase = i.getPhrase();
	return phrase;
}

bool Population::isFinished()
{
	if (maxFitness >= 1.0)
	{
		return true;
	}
	return false;
}

void generate()
{
	
}

Population::~Population()
{
}
