#include "particle_swarm.h"


particle_swarm::particle_swarm(int particle_number, int dimension, int min, int max)
{
	for (int i = 0; i < particle_number; i++)
	{
		particle temp;
		temp = particle(dimension, min, max);
		swarm.push_back(temp);
	}
}

particle_swarm::particle_swarm()
{

}

particle_swarm::~particle_swarm()
{

}
