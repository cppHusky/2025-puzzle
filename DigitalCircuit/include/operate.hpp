#pragma once
#include<array>
#include"preset.hpp"
namespace operate{
std::array<bool,preset::OutputNum> signal(std::array<bool,preset::InputNum>&,std::array<bool,preset::OutputNum>&);
void floyd(
	std::array<std::array<int,1<<preset::OutputNum>,1<<preset::OutputNum> &dist,
	std::array<std::array<int,1<<preset::OutputNum>,1<<preset::OutputNum> &prev
);
};//namespace operate
