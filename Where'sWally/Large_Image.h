
class Large_Image {
public:
	// Intergers 
	int Rows;
	int Columns;
	
	// Double pointer Data
    double* Data;

	virtual void Edit_Rows(int);
	virtual void Edit_Columns(int);
	virtual void Edit_Picture(double*);

	// 
	double* Reset_Image();
	int Reset_Rows();
	int Reset_Columns();
};