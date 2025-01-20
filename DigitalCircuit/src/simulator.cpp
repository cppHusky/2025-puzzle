#include<array>
#include<iostream>
#include"operate.hpp"
#include"preset.hpp"
int main(){
	std::array<bool,preset::InputNum> input;
	std::array<bool,preset::OutputNum> output;
	for(int o=0;o<preset::OutputNum;o++)
		std::cout<<(output[o]=false);
	while(true){
		std::cout<<std::endl;
		std::array<char,preset::InputNum> inputc;
		for(int i=preset::InputNum-1;i>=0;i--){
			std::cin>>inputc[i];
			input[i]=inputc[i]=='1'?true:false;
		}
		output=operate::signal(input,output);
		for(int o=preset::OutputNum-1;o>=0;o--)
			std::cout<<output[o];
	}
	return 0;
}
