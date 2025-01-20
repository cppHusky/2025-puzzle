#include<array>
#include"operate.hpp"
#include"preset.hpp"
std::array<bool,preset::OutputNum> operate::signal(std::array<bool,preset::InputNum> &input,std::array<bool,preset::OutputNum> &output){
	std::array<bool,preset::OutputNum> result;
	//result[7,5,3,1]记录了本次的输入
	result[7]=input[3];
	result[5]=input[2];
	result[3]=input[1];
	result[1]=input[0];
	//result[6]只有在「本次输入与上次输入完全相反」时，才会得到true
	result[6]=input[3]^output[7]&&input[2]^output[5]&&input[1]^output[3]&&input[0]^output[1];
	//result[4,2]组成二位计数器
	result[4]=output[4]^output[2];
	result[2]=!output[2];
	//result[0]等于所有输入、输出的异或和
	result[0]=false;
	for(int i=0;i<preset::InputNum;i++)
		result[0]^=input[i];
	for(int i=0;i<preset::OutputNum;i++)
		result[0]^=output[i];
	return result;
}
