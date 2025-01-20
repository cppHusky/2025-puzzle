#include<array>
#include<iostream>
#include<limits>
#include"operate.hpp"
#include"preset.hpp"
bool is_reflecxive(
	const std::array<std::array<int,1<<preset::OutputNum>,1<<preset::OutputNum> &prev
){
	for(int i=0;i<1<<preset::OutputNum;i++)
		if(![&,i]()->bool{
			for(int j=0;j<1<<preset::OutputNum;j++)
				if(i!=j&&prev[i][j]!=-1&&prev[j][i]!=-1)
					return true;
			return false;
		}())return false;
	return true;
}
bool is_symmetric(
	const std::array<std::array<int,1<<preset::OutputNum>,1<<preset::OutputNum> &prev
){
	for(int i=0;i<1<<preset::OutputNum;i++)
		for(int j=0;j<1<<preset::OutputNum;j++)
			if(i!=j&&prev[i][j]!=-1&&prev[j][i]==-1)
				return false;
	return true;
}
int main(){
	constexpr int start{0};
	constexpr int end{(1<<preset::OutputNum)-1};
	std::array<std::array<int,1<<preset::OutputNum>,1<<preset::OutputNum> dist,prev;
	operate::floyd(dist,prev);
	if(is_reflecxive(prev)){
		std::cout<<"The relation is reflecxive."<<std::endl;
		if(is_symmetric(prev))
			std::cout<<"The relation is symmetric."<<std::endl;
		else
			std::cout<<"The relation is anti-symmetric."<<std::endl;
	}
	else{
		std::cout<<"The relation is irreflecxive."<<std::endl;
		if(is_symmetric(prev))
			std::cout<<"The relation is symmetric."<<std::endl;
		else
			std::cout<<"The relation is assymmetric."<<std::endl;
	}
	for(int i=0;i<1<<preset::OutputNum;i++)
		if(prev[start][i]!=-1&&prev[i][end]==-1)
			std::cout<<i<<' ';
	std::cout<<std::endl;
	return 0;
}
