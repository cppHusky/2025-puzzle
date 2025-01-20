#include<array>
#include<fstream>
#include<iostream>
#include<iomanip>
#include"preset.hpp"
#include"operate.hpp"
int main(){
	std::ofstream fout{"./karnaugh.txt"};
	if(!fout.is_open())
		return 1;
	std::array<bool,preset::InputNum> input;
	std::array<bool,preset::OutputNum> output;
	fout<<std::left<<std::setw(preset::InputNum+1)<<"O\\I";
	for(int i=0;i<1<<preset::OutputNum;i++){
		for(int b=preset::OutputNum-1;b>=0;b--)
			fout<<static_cast<bool>(i&1<<b);
		fout<<' ';
	}
	for(int i=0;i<1<<preset::InputNum+preset::OutputNum;i++){
		if(i%(1<<preset::OutputNum)==0){
			fout<<std::endl;
			for(int b=preset::InputNum-1;b>=0;b--)
				fout<<static_cast<bool>(i&1<<b+preset::OutputNum);
			fout<<' ';
		}
		for(int b=0;b<preset::OutputNum;b++)
			output[b]=static_cast<bool>(i&1<<b);
		for(int b=0;b<preset::InputNum;b++)
			input[b]=static_cast<bool>(i&1<<b+preset::OutputNum);
		std::array<bool,preset::OutputNum> next=operate::signal(input,output);
		for(int b=preset::OutputNum-1;b>=0;b--)
			fout<<next[b];
		fout<<' ';
	}
	fout<<std::endl;
	return 0;
}
