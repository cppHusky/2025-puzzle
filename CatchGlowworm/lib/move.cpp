#include"coordinate.hpp"
#include"operate.hpp"
#include"preset.hpp"
extern coordinate::Coordinate you;
extern coordinate::Coordinate worm;
double operate::move(coordinate::Coordinate &you,coordinate::Coordinate &worm,double x,double y,double z){
	coordinate::Coordinate direction{coordinate::Coordinate{x,y,z}-you};
	if(direction.norm()>=1e-7){
		coordinate::Coordinate mydir{direction/10000};
		double dirlen{mydir.norm()};
		double wormdirlen{preset::WormSpeedRate*dirlen};
		for(int i=0;i<10000;i++){
			you+=mydir;
			worm+=(worm-you).normalize()*wormdirlen;
		}
	}
	return (worm-you).norm();
}
