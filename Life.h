#pragma once
#include <vector>
struct Cell {
	int value = 0;
	int nextState = 0;
};
using Matrix2d=std::vector<std::vector<Cell>>;
const unsigned int DEFAULT_SIZE=100;


void applyChanges(Matrix2d &Matrix);
void genNextGeneration(Matrix2d &Matrix);
void fullClear(Matrix2d &Matrix);
void GosperGun(Matrix2d &Matrix);
void Pentamino(Matrix2d &Matrix);
void GalaxyOfCocke(Matrix2d &Matrix);