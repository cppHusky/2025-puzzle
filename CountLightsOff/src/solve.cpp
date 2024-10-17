#include<iostream>
#include<fstream>
#include<unistd.h>
#include<sys/wait.h>
#include"preset.hpp"
#include"operate.hpp"
#include"gaussian.hpp"
int main(){
	int pipe_click[2];
	int pipe_count[2];
	if(pipe(pipe_click)==-1||pipe(pipe_count)==-1){
		std::cerr<<"Failed to create pipes"<<std::endl;
		return 1;
	}
	pid_t pid=fork();
	if(pid==-1){
		std::cerr<<"Failed to fork"<<std::endl;
		return 2;
	}
	if(pid==0){
		close(pipe_click[1]);
		close(pipe_count[0]);
		dup2(pipe_click[0],STDIN_FILENO);
		close(pipe_click[0]);
		dup2(pipe_count[1],STDOUT_FILENO);
		close(pipe_count[1]);
		execl("./clo","./clo","-f",nullptr);
		std::cerr<<"Failed to execute ./clo"<<std::endl;
		return 3;
	}
	else{
		close(pipe_click[0]);
		close(pipe_count[1]);
		bool *coefficient[N*M],*bmatrix[N*M];
		double *dmatrix[N*M];
		for(int i=0;i<N*M;i++){
			coefficient[i]=new bool[N*M];
			bmatrix[i]=new bool[N*M+1];
			dmatrix[i]=new double[N*M+1];
		}
		gaussian::getcoef(coefficient);
		unsigned b[N*M];
		gaussian::make_b(b,pipe_click,pipe_count);
		gaussian::make_matrix(dmatrix,coefficient,b);
		gaussian::gaussian_eliminate(dmatrix);
		for(int i=0;i<N*M;i++){
			for(int j=0;j<N*M+1;j++)
				std::clog<<(std::abs(dmatrix[i][j])>1e-5?dmatrix[i][j]:0)<<' ';
			std::clog<<std::endl;
		}
		close(pipe_click[1]);
		close(pipe_click[0]);
		for(int i=0;i<N*M;i++){
			delete []coefficient[i];
			delete []bmatrix[i];
			delete []dmatrix[i];
		}
		waitpid(pid,nullptr,0);
	}
	return 0;
}
