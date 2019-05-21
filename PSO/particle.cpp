#include "particle.h"

particle::particle()
{

}

particle::~particle()
{

}

particle::particle(int dimension, int min, int max)
{
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> distribution(min, max);
	auto random = std::bind(distribution, generator);

	for (int i = 0; i < dimension; i++)
	{
		position.push_back(random());
		velocity.push_back(random());

		pBest_position.push_back(position[i]);
	}

	pBest = 99999; 

}
