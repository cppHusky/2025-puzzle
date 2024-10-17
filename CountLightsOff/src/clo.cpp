#include<iostream>
#include<fstream>
#include<unistd.h>
#include"preset.hpp"
#include"random.hpp"
#include"operate.hpp"
int main(int argc,char *argv[]){
	const bool FILENO=argc>1?true:false;
	std::ofstream log{"log.txt"};
	auto clogbuf{std::clog.rdbuf()};
	std::clog.rdbuf(log.rdbuf());
	bool *light[M];
	for(int j=0;j<M;j++)
		light[j]=new bool[N];
	unsigned count_on=user::initialize(light,N,M);
	if(FILENO)
		write(STDOUT_FILENO,&count_on,sizeof(count_on));	
	else
		std::cout<<"Now: "<<count_on<<std::endl;
	while(count_on){
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				std::clog<<light[i][j]<<' ';
			std::clog<<'\n';
		}
		std::clog<<std::endl;
		unsigned i,j;
		if(FILENO){
			read(STDIN_FILENO,&i,sizeof(i));
			read(STDIN_FILENO,&j,sizeof(j));
		}
		else
			std::cin>>i>>j;
		count_on=user::click(light,N,M,i,j);
		if(count_on==-1){
			std::cerr<<"Error: invalid index "<<i<<" and "<<j<<std::endl;
			continue;
		}
		if(FILENO)
			write(STDOUT_FILENO,&count_on,sizeof(count_on));
		else
			std::cout<<"Now: "<<count_on<<std::endl;
	}
	for(int j=0;j<M;j++)
		delete light[j];
	std::clog.rdbuf(clogbuf);
	log.close();
	return 0;
}
