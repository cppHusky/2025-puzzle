#pragma once
#include<chrono>
#include<random>
namespace basic{
double inline get_random(){
	std::mt19937_64 rng;
	uint64_t timeSeed=std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq ss{uint32_t(timeSeed &0xffffffff),uint32_t(timeSeed>>32)};
	rng.seed(ss);
	std::uniform_real_distribution<double> unif(0,1);
	return unif(rng);
}
};//namespace basic
