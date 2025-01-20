#include<iostream>
#include<fstream>
#include"preset.hpp"
#include"gaussian.hpp"
int main(){
	bool *coefficient[N*M],*bmatrix[N*M];
	double *dmatrix[N*M];
	for(int i=0;i<N*M;i++){
		coefficient[i]=new bool[N*M];
		bmatrix[i]=new bool[N*M+1];
		dmatrix[i]=new double[N*M+1];
	}
	gaussian::getcoef(coefficient);
	unsigned b[N*M];
	gaussian::make_b(b,std::cin,std::cout);
	gaussian::make_matrix(dmatrix,coefficient,b);
	gaussian::gaussian_eliminate(dmatrix);
	for(int i=0;i<N*M;i++)
		b[i]=std::abs(dmatrix[i][N*M])>1e-5?1:0;
	gaussian::make_matrix(bmatrix,coefficient,b);
	gaussian::gaussian_eliminate(bmatrix);
	for(int i=0;i<N*M;i++)
		b[i]=std::abs(bmatrix[i][N*M]);
	for(int k=0;k<N*M;k++)
		if(b[k]==1){
			unsigned i{k/M},j{k%M},now;
			std::cout<<i+1<<' '<<j+1<<std::endl;
		}
	for(int i=0;i<N*M;i++){
		delete []coefficient[i];
		delete []bmatrix[i];
		delete []dmatrix[i];
	}
	return 0;
}
