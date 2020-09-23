#include "Large_Image.h"
#include "Matrix.h"
#include "Base_Image.h"
// Editing Functions

void Large_Image::Edit_Rows(int Value) {
	Rows = Value;
}
void Large_Image::Edit_Columns(int Value) {
	Columns = Value;
}
void Large_Image::Edit_Picture(double* Value) {
	Data = Value;
}

// Reset Functions

double* Large_Image::Reset_Image() {
	return Data;
}

int Large_Image::Reset_Columns() {
	return Columns;
}

int Large_Image::Reset_Rows() {
	return Rows;
}

