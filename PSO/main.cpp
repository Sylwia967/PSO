#include "particle.h"
#include "particle_swarm.h"
#include <stdio.h>
#include <stdlib.h>


#define GENERATION_NUMBER 100
#define PARTICLE_NUMBER 20
#define DIMENSION 4
#define MIN -10
#define MAX 10
#define W 0.6
#define C1 2.1
#define C2 2.1

double randomer();
double dimension2_fitness(double x1, double x2);
double dimension4_fitness(double x1, double x2, double x3, double x4);


int main() {

	particle_swarm PSO;
	PSO = particle_swarm(PARTICLE_NUMBER, DIMENSION, MIN, MAX);
	PSO.gbest = 99999;


	for (int i = 0; i < GENERATION_NUMBER; i++) {

		for (int i = 0; i < PARTICLE_NUMBER; i++)
			//KROK 1: fitness
			//PSO.swarm[i].fitness = dimension2_fitness(PSO.swarm[i].position[0], PSO.swarm[i].position[1]);
		PSO.swarm[i].fitness = dimension4_fitness(PSO.swarm[i].position[0], PSO.swarm[i].position[1], PSO.swarm[i].position[2], PSO.swarm[i].position[3]);

			//KROK 2: pBEST
			if (PSO.swarm[i].fitness < PSO.swarm[i].pBest) {
				PSO.swarm[i].pBest = PSO.swarm[i].fitness;
				PSO.swarm[i].pBest_position = PSO.swarm[i].position;
			}
			//KROK 3: gBEST
			if (PSO.swarm[i].fitness < PSO.gbest) {
				PSO.gbest = PSO.swarm[i].fitness;
				PSO.gbest_position = PSO.swarm[i].position;
				
			}

		

		//KROK 4
		for (int i = 0; i < PARTICLE_NUMBER; i++) 
			for (int j = 0; j < DIMENSION; j++) {
				PSO.swarm[i].velocity[j] = W * PSO.swarm[i].velocity[j] + C1 * randomer() * (PSO.swarm[i].pBest_position[j] - PSO.swarm[i].position[j]) + C2 * randomer() * (PSO.gbest_position[j]-PSO.swarm[i].position[j]);
			}

			for (int j = 0; j < DIMENSION; j++) {
				PSO.swarm[i].position[j] = PSO.swarm[i].position[j] + PSO.swarm[i].velocity[j];
			}

			

		}
	
	printf(
		"gbest=%lf,position[0]=%lf,position[1]=%lf,position[2]=%lf,position[3]=%lf", PSO.gbest,PSO.gbest_position[0],PSO.gbest_position[1], PSO.gbest_position[2], PSO.gbest_position[3]);


	return 0;
}

double dimension2_fitness(double x1, double x2) {

	double fitness;
	double pi = acos(-1);
	fitness = (x1 * x1 + x2 * x2 - 0.3 * cos(3 * pi * x1 * pi / 180) - 0.4 * cos(4 * pi * x2 * pi / 180) + 0.7); //funkcja 1

	//fitness = -((x1 + 2 * x2 - 7) * (x1 + 2 * x2 - 7) + (2 * x1 + x2 - 5) * (2 * x1 + x2 - 5)); //funkcja 5
	//fitness = ((-13 + x1 + ((5 - x2) * x2 - 2) * x2) * (-13 + x1 + ((5 - x2) * x2 - 2) * x2) + (-29 + x1 + ((x2 + 1) * x2 - 14) * x2) * (-29 + x1 + ((x2 + 1) * x2 - 14) * x2)); //funkcja 6

	return fitness;
}

double dimension4_fitness(double x1, double x2, double x3, double x4) {

	double fitness;

	//	fitness = (x1 + 10 * x2) + 5 * (x3 - x4) * (x3 - x4) + (x2 - 2 * x3)*(x2 - 2 * x3)*(x2 - 2 * x3) + 10 * (x1 - x4)*(x1 - x4)*(x1 - x4)*(x1 - x4);

	fitness = (x1 - 1) * (x1 - 1) + (x2 - 1) * (x2 - 1) + (x3 - 1) * (x3 - 1) + (x4 - 1) * (x4 - 1)
		+ 1 * (x1 - 1) * (x1 - 1) + 2 * (x2 - 1) * (x2 - 1) + 3 * (x3 - 1) * (x3 - 1) + 4 * (x4 - 1) * (x4 - 1)
		+ 1 * (x1 - 1) * (x1 - 1) * (x1 - 1) * (x1 - 1) + 2 * (x2 - 1) * (x2 - 1) * (x2 - 1) * (x2 - 1) + 3 * (x3 - 1) * (x3 - 1) * (x3 - 1) * (x3 - 1) + 4 * (x4 - 1) * (x4 - 1) * (x4 - 1) * (x4 - 1);

	return fitness;

}

double randomer() {

	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> distribution(0, 1);
	auto random = std::bind(distribution, generator);

	return random();

}