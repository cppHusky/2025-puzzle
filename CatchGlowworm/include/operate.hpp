#pragma once
#include"coordinate.hpp"
namespace operate{
void initialize(coordinate::Coordinate &you,coordinate::Coordinate &worm);
double move(coordinate::Coordinate &you,coordinate::Coordinate &worm,double x,double y,double z);
double get_theta(double d0,double d1,double delta);
};//namespace operate
