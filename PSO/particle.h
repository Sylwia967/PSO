#pragma once
#include <vector>
#include <vector>
#include <random>
#include <functional>

using namespace std;

class particle
{
public:
	particle();
	particle(int dimension, int min, int max);
	~particle();

	vector<double> position;
	vector<double> velocity;

	double fitness;

	double pBest;
	vector<double> pBest_position;


private:

};