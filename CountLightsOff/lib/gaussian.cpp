#include<unistd.h>
#include<algorithm>
#include<cmath>
#include"preset.hpp"
#include"gaussian.hpp"
void gaussian::make_b(unsigned *b,int *pipe_click,int *pipe_count){
	unsigned last,now;
	read(pipe_count[0],&now,sizeof(now));
	for(unsigned i=0;i<N;i++)
		for(unsigned j=0;j<M;j++){
			write(pipe_click[1],&i,sizeof(i));
			write(pipe_click[1],&j,sizeof(j));
			last=now;
			read(pipe_count[0],&now,sizeof(now));
			if((i==0||i==N-1)&&(j==0||j==M-1))
				b[i*M+j]=(3+last-now)/2;
			else if(i==0||i==N-1||j==0||j==M-1)
				b[i*M+j]=(4+last-now)/2;
			else
				b[i*M+j]=(5+last-now)/2;
			write(pipe_click[1],&i,sizeof(i));
			write(pipe_click[1],&j,sizeof(j));
			read(pipe_count[0],&now,sizeof(now));
		}
}
void gaussian::make_matrix(double **matrix,bool *const *coefficient,const unsigned *b){
	for(int i=0;i<N*M;i++){
		for(int j=0;j<N*M;j++)
			matrix[i][j]=coefficient[i][j];
		matrix[i][N*M]=b[i];
	}
}
void gaussian::make_matrix(bool **matrix,bool *const *coefficient,const unsigned *b){
	for(int i=0;i<N*M;i++){
		for(int j=0;j<N*M;j++)
			matrix[i][j]=coefficient[i][j];
		matrix[i][N*M]=b[i];
	}
}
int gaussian::gaussian_eliminate(double **matrix){
	int row{0},column{0};
	while(row<N*M&&column<N*M){
		int max_index=row;
		double max=std::abs(matrix[row][column]);
		for(int i=row+1;i<N*M;i++)
			if(std::abs(matrix[i][column])>max){
				max_index=i;
				max=std::abs(matrix[i][column]);
			}
		if(max<1e-5){
			column++;
			continue;
		}
		std::swap(matrix[max_index],matrix[row]);
		for(int i=row+1;i<N*M;i++)
			if(std::abs(matrix[i][column])>1e-5){
				double rate=matrix[i][column]/matrix[row][column];
				for(int j=0;j<N*M+1;j++)
					matrix[i][j]-=matrix[row][j]*rate;
			}
		row++;
	}
	for(row=N*M-1;row>=0;row--){
		int y{-1};
		for(int j=0;j<N*M+1;j++)
			if(std::abs(matrix[row][j])>1e-5){
				y=j;
				break;
			}
		if(y>=0&&y<N*M)
			for(int i=0;i<row;i++)
				if(std::abs(matrix[i][y])>1e-5){
					double rate=matrix[i][y]/matrix[row][y];
					for(int j=y;j<N*M+1;j++)
						if(std::abs(matrix[row][j])>1e-5)
							matrix[i][j]-=matrix[row][j]*rate;
				}
		else if(y==N*M)
			return -1;
	}
	for(int i=0;i<N*M;i++){
		int j{0};
		while(std::abs(matrix[i][j])<1e-5&&j<N*M+1)
			j++;
		double rate=matrix[i][j];
		while(j<N*M+1)
			matrix[i][j++]/=rate;
	}
	return 0;
}
int gaussian::gaussian_eliminate(bool **matrix){
	int row{0},column{0};
	while(row<N*M&&column<N*M){
		int max_index=row;
		bool max=matrix[row][column];
		for(int i=row+1;i<N*M;i++)
			if(matrix[i][column]){
				max_index=i;
				max=true;
			}
		if(!max){
			column++;
			continue;
		}
		std::swap(matrix[max_index],matrix[row]);
		for(int i=row+1;i<N*M;i++)
			if(matrix[i][column])
				for(int j=0;j<N*M+1;j++)
					if(matrix[row][j])
						matrix[i][j]=!matrix[i][j];
		row++;
	}
	for(row=N*M-1;row>=0;row--){
		int y{-1};
		for(int j=0;j<N*M+1;j++)
			if(matrix[row][j]){
				y=j;
				break;
			}
		if(y>=0&&y<N*M)
			for(int i=0;i<row;i++)
				if(matrix[i][y])
					for(int j=y;j<N*M+1;j++)
						if(matrix[row][j])
							matrix[i][j]=!matrix[i][j];
		else if(y==N*M)
			return -1;
	}
	return 0;
}
