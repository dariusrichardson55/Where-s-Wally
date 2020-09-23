class Ref_Image {
	int Rows;
	int Columns;
	double* Data;
public:
	// Modifies the rows, columns and Picture 
	virtual void Edit_Rows(int);
	virtual void Edit_Columns(int);
	virtual void Edit_Picture(double*);
	
	// Inputs them back 
	virtual double* Reset_Image();
	virtual int Reset_Rows();
	virtual int Reset_Columns();

};
