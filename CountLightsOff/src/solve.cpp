#include<iostream>
#include<fstream>
#include<unistd.h>
#include<sys/wait.h>
#include"preset.hpp"
#include"operate.hpp"
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
		int last,now;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++){
				write(pipe_click[1],&i,sizeof(i));
				write(pipe_click[1],&j,sizeof(j));
				last=now;
				read(pipe_count[0],&now,sizeof(now));
			}
		close(pipe_click[1]);
		close(pipe_click[0]);
		waitpid(pid,nullptr,0);
	}
	return 0;
}
