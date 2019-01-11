  #include "DNA.h"
#include <string>
#include <random>
#include <ctime>


DNA::DNA(int num)
	: child{ nullptr }
{
	char letters[] = "abcdefghijklmnopqrstuvwxyz ";
	for (int i = 0; i < num; ++i)
	{
		char x = letters[rand() % 27];
		genes.push_back(x);
		//genes.push_back(static_cast<char>(32) + (rand() % 91));
		//genes.at(i) = (static_cast<char>(32) + (rand() % 91));
	}
	getPhrase();
}



string DNA::getPhrase()
{
	string phrase;
	string p (genes.data(), genes.size());
	return p;
}

float DNA::fitness(string target)
{
	auto score = 0;
	for(auto a = 0; a < target.length(); ++a)
	{
		if(genes.at(a) == target[a])
		{
			score++;
		}
	}
	float fit = static_cast<float>(score) / target.length();
	fit = (fit * fit) + abs(0.01);
	
	return fit;
	
}

DNA *DNA::crossover(DNA & partner)
{
	auto *child = new DNA(genes.size());

	auto midpoint = rand() % genes.size();

	for (auto i = 0; i < genes.size(); ++i)
	{
		if (i > midpoint)
		{
			child->genes.at(i) = genes.at(i);
		}
		else
		{
			child->genes.at(i) = partner.genes.at(i);
		}
	}
	return child;
}

void DNA::mutate(float mutationRate)
{
	char letters[] = "abcdefghijklmnopqrstuvwxyz ";
	for (int i = 0; i < genes.size(); ++i)
	{
		float r = (rand()) / (float(RAND_MAX) + 1.0);

		if (r < mutationRate)
		{
			char x = letters[rand() % 27];
			genes.at(i) = x;
		}
	}
}
DNA::~DNA()
{
	if (child != nullptr)
	{
		delete child;
	}
}
