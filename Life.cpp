#include "Life.h"

void fullClear(Matrix2d &Matrix){
	for(int i=0;i<Matrix.size();++i){
		for(int j=0;j<Matrix[i].size();++j){
			Matrix[i][j].value=0;
		}
	}
}

void genNextGeneration(Matrix2d &Matrix){
	for(int i=1;i<Matrix.size()-1;++i){
		for(int j=1;j<Matrix[i].size()-1;++j){
			int	criteria=(Matrix[i+1][j].value)+
						 (Matrix[i+1][j+1].value)+
						 (Matrix[i+1][j-1].value)+
						 (Matrix[i-1][j+1].value)+
						 (Matrix[i][j+1].value)+
						 (Matrix[i][j-1].value)+
						 (Matrix[i-1][j].value)+
						 (Matrix[i-1][j-1].value);
			if(Matrix[i][j].value==0){
				if(criteria==3){
					Matrix[i][j].nextState = 1;
				}else{ 
					Matrix[i][j].nextState = 0;
				}
			}else{
				if(criteria==3||criteria==2){
					Matrix[i][j].nextState = 1;
				}else{
					Matrix[i][j].nextState = 0;
				}
			}

		}

	}
}
void applyChanges(Matrix2d &Matrix){
	for(int i=0;i<Matrix.size();++i){
		for(int j=0;j<Matrix[i].size();++j){
			Matrix[i][j].value=Matrix[i][j].nextState;
		}
	}
}
	void  GosperGun(Matrix2d &Matrix){//Планерное ружьё Госпера.
		fullClear(Matrix);
		Matrix[18][4-1].value=1;
		Matrix[18][5-1].value=1;
		Matrix[17][5-1].value=1;
		Matrix[17][4-1].value=1;
		Matrix[20][17-1].value=1;
		Matrix[20][16-1].value=1;
		Matrix[19][15-1].value=1;
		Matrix[18][14-1].value=1;
		Matrix[17][14-1].value=1;
		Matrix[16][14-1].value=1;
		Matrix[15][15-1].value=1;
		Matrix[14][16-1].value=1;
		Matrix[14][17-1].value=1;
		Matrix[15][19-1].value=1;
		Matrix[16][20-1].value=1;
		Matrix[17][20-1].value=1;
		Matrix[18][20-1].value=1;
		Matrix[19][19-1].value=1;
		Matrix[17][18-1].value=1;
		Matrix[17][21-1].value=1;
		Matrix[18][24-1].value=1;
		Matrix[18][25-1].value=1;
		Matrix[19][24-1].value=1;
		Matrix[19][25-1].value=1;
		Matrix[20][24-1].value=1;
		Matrix[20][25-1].value=1;
		Matrix[17][26-1].value=1;
		Matrix[21][26-1].value=1;
		Matrix[21][28-1].value=1;
		Matrix[22][28-1].value=1;
		Matrix[17][28-1].value=1;
		Matrix[16][28-1].value=1;
		Matrix[18][38-1].value=1;
		Matrix[18][39-1].value=1;
		Matrix[19][38-1].value=1;
		Matrix[19][39-1].value=1;
}
void  Pentamino(Matrix2d &Matrix){
		fullClear(Matrix);
		Matrix[(Matrix.size())/2][(Matrix.size())/2].value=1;
		Matrix[(Matrix.size()/2)+1][(Matrix.size())/2].value=1;
		Matrix[((Matrix.size())/2)+1][(Matrix.size())/2+1].value=1;
		Matrix[((Matrix.size())/2)-1][(Matrix.size())/2].value=1;
		Matrix[(Matrix.size())/2][((Matrix.size())/2)-1].value=1;
	}
	void  GalaxyOfCocke(Matrix2d &Matrix){
		fullClear(Matrix);
		Matrix[30][30].value=1;
		Matrix[30][31].value=1;
		Matrix[30][32].value=1;
		Matrix[30][33].value=1;
		Matrix[30][34].value=1;
		Matrix[30][35].value=1;
		Matrix[31][30].value=1;
		Matrix[31][31].value=1;
		Matrix[31][32].value=1;
		Matrix[31][33].value=1;
		Matrix[31][34].value=1;
		Matrix[31][35].value=1;
		Matrix[30][38].value=1;
		Matrix[31][38].value=1;
		Matrix[32][38].value=1;
		Matrix[33][38].value=1;
		Matrix[34][38].value=1;
		Matrix[35][38].value=1;
		Matrix[30][37].value=1;
		Matrix[31][37].value=1;
		Matrix[32][37].value=1;
		Matrix[33][37].value=1;
		Matrix[34][37].value=1;
		Matrix[35][37].value=1;
		Matrix[37][38].value=1;
		Matrix[37][37].value=1;
		Matrix[37][36].value=1;
		Matrix[37][35].value=1;
		Matrix[37][34].value=1;
		Matrix[37][33].value=1;
		Matrix[38][38].value=1;
		Matrix[38][37].value=1;
		Matrix[38][36].value=1;
		Matrix[38][35].value=1;
		Matrix[38][34].value=1;
		Matrix[38][33].value=1;
		Matrix[38][31].value=1;
		Matrix[37][31].value=1;
		Matrix[36][31].value=1;
		Matrix[35][31].value=1;
		Matrix[34][31].value=1;
		Matrix[33][31].value=1;
		Matrix[38][30].value=1;
		Matrix[37][30].value=1;
		Matrix[36][30].value=1;
		Matrix[35][30].value=1;
		Matrix[34][30].value=1;
		Matrix[33][30].value=1;
	}