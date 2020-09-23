#pragma once
class Matrix {
	// Integers
	int rows = 0;
	int columns = 0;
	int x = 0;
	int y = 0;
	// Doubles (Pointer and double pointer)
	double** matrix = 0;
	double* rowIndex;
public:
	Matrix();
	Matrix(int, int);
	virtual void Deallocate();
	virtual double** Allocate(int, int);

	~Matrix();

	virtual double** setSize(int, int);
	virtual double* getMatrix();
	virtual double* getRow(int);
	virtual double* getColumn(int);
	double Cluttered_scene_vector;
	double Wally_vector;


};