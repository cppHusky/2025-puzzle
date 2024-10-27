#include<iostream>
#include<iomanip>
#include<fstream>
#include<unistd.h>
#include<sys/wait.h>
#include"preset.hpp"
void write_xyz(double,double,double,int*);
int main(){
	int pipe_input[2];
	int pipe_output[2];
	if(pipe(pipe_input)==-1||pipe(pipe_output)==-1){
		std::cerr<<"Failed to create pipes."<<std::endl;
		return 1;
	}
	pid_t pid=fork();
	if(pid==-1){
		std::cerr<<"Failed to fork."<<std::endl;
		return 2;
	}
	if(pid==0){
		close(pipe_input[1]);
		close(pipe_output[0]);
		dup2(pipe_input[0],STDIN_FILENO);
		close(pipe_input[0]);
		dup2(pipe_output[1],STDOUT_FILENO);
		close(pipe_output[1]);
		execl("./cg","./cg","-f",nullptr);
		std::cerr<<"Failed to execute ./cg"<<std::endl;
		return 3;
	}
	else{
		std::clog<<std::setprecision(15);
		close(pipe_input[0]);
		close(pipe_output[1]);
		unsigned round{0};
		double d[5],x,y,z,delta{.0001},wormdelta;
		read(pipe_output[0],d+0,sizeof(double));
		std::clog<<"Round "<<++round<<": d[0]="<<d[0]<<std::endl;
		write_xyz(delta,0,0,pipe_input);
		read(pipe_output[0],d+1,sizeof(double));
		std::clog<<"Round "<<++round<<": d[1]="<<d[1]<<std::endl;
		write_xyz(delta,delta,0,pipe_input);
		read(pipe_output[0],d+2,sizeof(double));
		std::clog<<"Round "<<++round<<": d[2]="<<d[2]<<std::endl;
		write_xyz(delta,delta,delta,pipe_input);
		read(pipe_output[0],d+3,sizeof(double));
		std::clog<<"Round "<<++round<<": d[3]="<<d[3]<<std::endl;
		wormdelta=d[0]+preset::WormSpeedRate*delta;
		x=2*d[3]*((wormdelta*wormdelta+delta*delta-d[1]*d[1])/(2*delta*wormdelta))+delta;
		wormdelta=d[1]+preset::WormSpeedRate*delta;
		y=2*d[3]*((wormdelta*wormdelta+delta*delta-d[2]*d[2])/(2*delta*wormdelta))+delta;
		wormdelta=d[2]+preset::WormSpeedRate*delta;
		z=2*d[3]*((wormdelta*wormdelta+delta*delta-d[3]*d[3])/(2*delta*wormdelta))+delta;
		std::clog<<"x="<<x<<", y="<<y<<", z="<<z<<std::endl;
		write_xyz(x,y,z,pipe_input);
		read(pipe_output[0],d+4,sizeof(double));
		std::clog<<"Round "<<++round<<": d[4]="<<d[4]<<std::endl;
		close(pipe_input[1]);
		close(pipe_output[0]);
		waitpid(pid,nullptr,0);
	}
	return 0;
}
void write_xyz(double x,double y,double z,int *pipe_input){
	write(pipe_input[1],&x,sizeof(x));
	write(pipe_input[1],&y,sizeof(y));
	write(pipe_input[1],&z,sizeof(z));
}
