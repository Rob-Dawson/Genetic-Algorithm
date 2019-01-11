#include <iostream>
#include <string>
#include "Population.h"
#include <ctime>
using namespace std;


int main() 
{
	srand(time(0));

	auto target = "the the    the";
	auto populationMax = 300;
	auto mutationRate = 0.05f;
	auto population = 1;
	int generations = 0;
	
	auto *pop = new Population(target, mutationRate, populationMax);
	while (!pop->finished)
	{
		pop->selection();
		pop->calcFitness();
		cout << "Generation: " << generations++ << "\n ===== ";
		string phrase = pop->getBest();
		cout << "Phrase: " << phrase << "\n ===== ";
	}
		
	//delete pop;

	system("pause");
}