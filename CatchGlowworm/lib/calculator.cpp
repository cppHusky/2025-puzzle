#include<cmath>
#include"preset.hpp"
#include"operate.hpp"
double operate::get_theta(double d0,double d1,double delta){
	double d=d0+preset::WormSpeedRate*delta;
	return std::acos((d*d+delta*delta-d1*d1)/(2*delta*d));
}
