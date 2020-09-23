#include <iostream>
#include "Matrix.h"
#include "Base_Image.h"

using namespace std;



Matrix::Matrix() {
	matrix = Allocate(0, 0);
}

Matrix::Matrix(int ro, int col) {
	matrix = Allocate(ro, col);
}
void Matrix::Deallocate() {
	for (int row = 0; row < x; row++) {
		delete[] matrix[row];
	}
	delete[] matrix;
}

double ** Matrix::Allocate(int rows, int cols) {
	x = rows;
	y = columns;
	double ** new_matrix = new double *[rows];
	for (int row = 0; row < rows; row++) {
		new_matrix[row] = new double[columns];
	}
	return new_matrix;
}

Matrix::~Matrix() {
	Deallocate();
}

double** Matrix::setSize(int rows, int columns) {
	if (rows > x && columns > y) {
		double ** new_matrix = Allocate(rows, columns);
		for (int i = 0; i < rows; i++) {
			new_matrix[i] = matrix[i];
		}
		Deallocate();
		return new_matrix;
	}
	else {
		return matrix;
	}
}
double* Matrix::getMatrix() {
	double* start = matrix[0];
	return start;
}
double* Matrix::getRow(int row) {
	if (row > x) {
		cout << "Error the row of the index"  << endl;
	}
	else {
		double *rowIndex = matrix[row];
		return rowIndex;
	}
	return 0;
}
double*Matrix::getColumn(int column) {
	if (column > y) {
		cout << "Error the column of the index"  << endl;
	}
	else {
		double * columnIndex = &matrix[0][y];
		return rowIndex;
	}
	return 0;
}

