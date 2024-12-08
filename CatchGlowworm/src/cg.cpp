#include<iostream>
#include<fstream>
#include<iomanip>
#include"coordinate.hpp"
#include"preset.hpp"
#include"operate.hpp"
int main(){
	std::ofstream log{"log.txt"};
	auto clogbuf{std::clog.rdbuf()};
	std::clog.rdbuf(log.rdbuf());
	coordinate::Coordinate you,worm;
	std::cout<<std::setprecision(15);
	std::clog<<std::setprecision(15);
	while(true){
		operate::initialize(you,worm);
		std::cout<<(worm-you).norm()<<std::endl;
		std::clog<<"You: ("<<you.x()<<","<<you.y()<<","<<you.z()<<")\n"
		<<"Worm: ("<<worm.x()<<","<<worm.y()<<","<<worm.z()<<")"<<std::endl;
		while(worm.norm()<=10&&((worm-you).norm()>.1)){
			double x,y,z;
			std::cin>>x>>y>>z;
			operate::move(you,worm,x,y,z);
			std::cout<<(worm-you).norm()<<std::endl;
			std::clog<<"You: ("<<you.x()<<","<<you.y()<<","<<you.z()<<")\n"
				<<"Worm: ("<<worm.x()<<","<<worm.y()<<","<<worm.z()<<")"<<std::endl;
		}
		if((worm-you).norm()<=.1)
			break;
	}
	std::clog.rdbuf(clogbuf);
	log.close();
	return 0;
}
