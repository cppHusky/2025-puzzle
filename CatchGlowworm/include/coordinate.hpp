#pragma once
#include<cmath>
namespace coordinate{
class Coordinate{
	private:
		double _x;
		double _y;
		double _z;
	public:
		Coordinate()
			:_x{0},_y{0},_z{0}{}
		Coordinate(double x,double y,double z)
			:_x{x},_y{y},_z{z}{}
		double x()const{return _x;}
		double y()const{return _y;}
		double z()const{return _z;}
		double norm()const{
			return std::sqrt(_x*_x+_y*_y+_z*_z);
		}
		Coordinate normalize()const{
			return Coordinate{*this/norm()};
		}
		Coordinate operator-()const{
			return Coordinate{-_x,-_y,-_z};
		}
		Coordinate operator+(const Coordinate &c)const{
			return Coordinate{_x+c._x,_y+c._y,_z+c._z};
		}
		Coordinate operator-(const Coordinate &c)const{
			return *this+-c;
		}
		Coordinate operator*(double r)const{
			return Coordinate{_x*r,_y*r,_z*r};
		}
		Coordinate operator/(double r)const{
			return *this*(1/r);
		}
		Coordinate operator+=(const Coordinate &a){
			_x+=a._x;
			_y+=a._y;
			_z+=a._z;
			return *this;
		}
};
};//namespace coordinate
