#include<iostream>
#include<fstream>
#include"random.hpp"
#include"operate.hpp"
int main(){
	std::ofstream log{"log.txt"};
	auto clogbuf{std::clog.rdbuf()};
	std::clog.rdbuf(log.rdbuf());
	constexpr unsigned N=3;
	constexpr unsigned M=3;
	bool *light[M];
	for(int j=0;j<M;j++)
		light[j]=new bool[N];
	unsigned count_on=user::initialize(light,N,M);
	std::cout<<"Now: "<<count_on<<std::endl;
	while(count_on){
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				std::clog<<light[i][j]<<' ';
			std::clog<<'\n';
		}
		std::clog<<std::endl;
		unsigned i,j;
		std::cin>>i>>j;
		count_on=user::click(light,N,M,i,j);
		if(count_on==-1){
			std::cerr<<"Error: invalid index"<<std::endl;
			continue;
		}
		std::cout<<"Now: "<<count_on<<std::endl;
	}
	std::cout<<"You win!"<<std::endl;
	for(int j=0;j<M;j++)
		delete light[j];
	std::clog.rdbuf(clogbuf);
	log.close();
	return 0;
}
