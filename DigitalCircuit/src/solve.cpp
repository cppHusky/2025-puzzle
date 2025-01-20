#include<array>
#include<bitset>
#include<iostream>
#include"operate.hpp"
#include"preset.hpp"
#include<forward_list>
int main(){
	constexpr int start{0};
	int end{(1<<preset::OutputNum)-1};
	std::array<std::array<int,1<<preset::OutputNum>,1<<preset::OutputNum> dist,prev;
	operate::floyd(dist,prev);
	if(prev[start][end]==-1)
		std::cout<<"No way."<<std::endl;
	else{
		std::forward_list<int> path{end};
		while(start!=end){
			end=prev[start][end];
			path.push_front(end);
		}
		for(int p:path)
			std::cout<<std::bitset<preset::OutputNum>(p).to_string()<<' ';
	}
	return 0;
}
