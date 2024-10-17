#include"operate.hpp"
unsigned user::click(bool **lights,const unsigned N,const unsigned M,const unsigned i,const unsigned j){
	//click on position (i,j) in N*M matrix `lights`
	if(i>=N&&j>=M){
		//Error:invalid index
		return -1;
	}
	lights[i][j]=!lights[i][j];
	if(i>0)
		lights[i-1][j]=!lights[i-1][j];
	if(i<N-1)
		lights[i+1][j]=!lights[i+1][j];
	if(j>0)
		lights[i][j-1]=!lights[i][j-1];
	if(j<M-1)
		lights[i][j+1]=!lights[i][j+1];
	unsigned count_on{0};
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			count_on+=lights[i][j];
	return count_on;
}
