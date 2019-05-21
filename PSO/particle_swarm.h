#pragma once
#include "particle.h"



class particle_swarm
{
public:
	particle_swarm();
	particle_swarm(int particle_number, int dimension, int min, int max);
	~particle_swarm();


	vector<particle> swarm;
	double dimension2_fitness();

	double gbest;
	vector <double> gbest_position;



private:


};