#include"random.hpp"
#include"operate.hpp"
unsigned operate::initialize(bool **light,const unsigned N,const unsigned M){
	unsigned count_on{0};
	while(!count_on){
		count_on=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(basic::get_random()<.5)
					light[i][j]=false;
				else
					count_on+=light[i][j]=true;
	}
	return count_on;
}
