#include <iostream>
#include "Ref_Image.h"
#include "Matrix.h"
#include "Base_Image.h"

using namespace std;

// Editing Functions



	void Ref_Image::Edit_Rows(int Value) {
		Rows = Value;
	}
	void Ref_Image::Edit_Columns(int Value) {
		Columns = Value;
	}
	void Ref_Image::Edit_Picture(double* Value) {
		Data = Value;
	}

	// Reset Functions


	double*  Ref_Image::Reset_Image() {

	
		return Data;
	}

	int Ref_Image::Reset_Columns() {
		return Columns;
	}

	int Ref_Image::Reset_Rows() {
		return Rows;
	}


