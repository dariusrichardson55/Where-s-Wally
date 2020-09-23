#include "Base_Image.h"

// Editing Functions


void Base_Image::Edit_Rows(int Value) {
	Rows = Value;
}
void Base_Image::Edit_Columns(int Value) {
	Columns = Value;
}
void Base_Image::Edit_Picture(double* Value) {
	Data = Value;
}

// Reset Functions

double* Base_Image::Reset_Image() {
	return Data;
}
int Base_Image::Reset_Columns() {
	return Columns;
}
int Base_Image::Reset_Rows() {
	return Rows;
}