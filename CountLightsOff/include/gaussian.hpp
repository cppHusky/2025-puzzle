#pragma once
namespace gaussian{
void getcoef(bool**);
void make_b(unsigned*,int*,int*);
void make_matrix(double**,bool *const*,const unsigned*);
void make_matrix(bool**,bool* const*,const unsigned*);
int gaussian_eliminate(double **);
};//namespace gaussian
