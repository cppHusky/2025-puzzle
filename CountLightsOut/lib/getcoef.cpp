#include"preset.hpp"
#include"gaussian.hpp"
void gaussian::getcoef(bool **coefficient){
	for(int i=0;i<N*M;i++)
		for(int j=0;j<N*M;j++){
			int ix{i/M},iy{i%M},jx{j/M},jy{j%M};
			if(ix==jx){
				int dy{iy-jy};
				if(dy<=1&&dy>=-1)
					coefficient[i][j]=true;
			}
			else if(iy==jy){
				int dx{ix-jx};
				if(dx<=1&&dx>=-1)
					coefficient[i][j]=true;
			}
			else
				coefficient[i][j]=false;
		}
}
