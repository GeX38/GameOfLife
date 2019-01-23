#include "life.h"
void fullClear(Matrix2d &Matrix){
	for(int i=0;i<Matrix.size();++i){
		for(int j=0;j<Matrix[i].size();++j){
			Matrix[i][j].value=0;
		}
	};
	void  GosperGun(Matrix2d &Matrix){
		Matrix[1][1].value=1

	}