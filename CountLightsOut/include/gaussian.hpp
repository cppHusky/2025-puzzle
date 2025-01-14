#pragma once
#include<iostream>
namespace gaussian{
void getcoef(bool**);
void make_b(unsigned*,std::istream&,std::ostream&);
void make_matrix(double**,bool *const*,const unsigned*);
void make_matrix(bool**,bool* const*,const unsigned*);
int gaussian_eliminate(double **);
int gaussian_eliminate(bool **);
};//namespace gaussian
