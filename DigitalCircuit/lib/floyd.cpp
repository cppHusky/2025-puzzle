#include<array>
#include<limits>
#include"operate.hpp"
#include"preset.hpp"
void operate::floyd(
	std::array<std::array<int,1<<preset::OutputNum>,1<<preset::OutputNum> &dist,
	std::array<std::array<int,1<<preset::OutputNum>,1<<preset::OutputNum> &prev
){
	for(int o=0;o<1<<preset::OutputNum;o++)
		for(int r=0;r<1<<preset::OutputNum;r++){
			dist[o][r]=std::numeric_limits<int>::max()/2;
			prev[o][r]=-1;
		}
	for(int o=0;o<1<<preset::OutputNum;o++){
		dist[o][o]=0;
		prev[o][o]=o;
		std::array<bool,preset::OutputNum> output;
		for(int d=0;d<preset::OutputNum;d++)
			output[d]=o&1<<d;
		for(int i=0;i<1<<preset::InputNum;i++){
			std::array<bool,preset::InputNum> input;
			for(int d=0;d<preset::InputNum;d++)
				input[d]=i&1<<d;
			std::array<bool,preset::OutputNum> result{operate::signal(input,output)};
			int r{0};
			for(int d=0;d<preset::OutputNum;d++)
				if(result[d])
					r+=1<<d;
			dist[o][r]=1;
			prev[o][r]=o;
		}
	}
	for(int k=0;k<1<<preset::OutputNum;k++)
		for(int i=0;i<1<<preset::OutputNum;i++)
			for(int j=0;j<1<<preset::OutputNum;j++)
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					prev[i][j]=prev[k][j];
				}
}
