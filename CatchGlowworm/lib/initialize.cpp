#include<numbers>
#include<cmath>
#include"coordinate.hpp"
#include"random.hpp"
#include"preset.hpp"
namespace operate{
void initialize(coordinate::Coordinate &you,coordinate::Coordinate &worm){
	double rho=preset::MinInitDis+(preset::MaxInitDis-preset::MinInitDis)*basic::get_random();	
	double phi=2*std::numbers::pi*basic::get_random();
	double theta=(basic::get_random()-.5)*std::numbers::pi;
	you=coordinate::Coordinate{0,0,0};
	worm=coordinate::Coordinate{
		rho*std::cos(phi)*std::cos(theta),
		rho*std::sin(phi)*std::cos(theta),
		rho*std::sin(theta)
	};
}
};//namespace operate
