// Headers
#include "Matrix.h"
#include "Base_Image.h"
#include "Large_Image.h"
#include "Ref_Image.h"

// Functions
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
	int NumberofPoints, Start_X_coordinates, Start_Y_coordinates, End_X_coordinates, End_Y_coordinates;	
};

void write_pgm(string filename, double *data, int sizeR, int sizeC, int Q) {
	int i, j;
	unsigned char *image;
	ofstream myfile;

	image = (unsigned char *) new unsigned char[sizeR*sizeC];

	// convert the integer values to unsigned char

	for (i = 0; i < sizeR*sizeC; i++)
		image[i] = (unsigned char)data[i];

	myfile.open(filename, ios::out | ios::binary | ios::trunc);

	if (!myfile) {
		std::cout << "Can't open file: " << filename << endl;
		exit(1);
	}

	myfile << "P5" << endl;
	myfile << sizeC << " " << sizeR << endl;
	myfile << Q << endl;

	myfile.write(reinterpret_cast<char *>(image), (sizeR*sizeC) * sizeof(unsigned char));

	if (myfile.fail()) {
		std::cout << "Can't write image " << filename << endl;
		exit(0);
	}

	myfile.close();

	delete[] image;
}

double* read_text(string fileName, int sizeR, int sizeC) {
	double* data = new double[sizeR*sizeC];
	int i = 0;

	ifstream myfile(fileName);

	if (myfile.is_open()) {
		while (myfile.good()) {
			if (i > sizeR*sizeC - 1) break;
			myfile >> *(data + i);
			//cout << *(data + i) << ' '; // This line display the converted data on the screen, you may comment it out. 
			i++;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";

	//cout << i;
	return data;
}

int Count_number_of_rows(string FileName) {
	int Rows = 0;
	string line;

	ifstream file(FileName);

	while (getline(file, line))
		Rows++;
	return Rows;
}

int Count_number_of_columns(string FileName) {
	ifstream file2(FileName);
	string line2, temp;
	stringstream ss;
	int ncols = 0;

	getline(file2, line2);
	ss.clear();
	ss << line2;

	while (ss >> temp) {
		++ncols;
	}

	return ncols;
}

// Check wally in thr rows and and columns
bool CheckWally(double** Wally_2D, int CurrentPosition, double Value, Base_Image Wally) {
	bool Exists = false;
	int Position = 0;

	for (int x = 0; x <= (Wally.Reset_Rows() - 1); x++) {
		for (int y = 0; y <= (Wally.Reset_Columns() - 1); y++) {
			if (Wally_2D[x][y] != 255) {
				if (Position == CurrentPosition) {
					if (Wally_2D[x][y] == Value) {
						Exists = true;
					}
				}
				Position++;
			}
		}
	}

	return Exists;

}
// Compare each txt file until match is found

void FindWally(Base_Image Wally, Large_Image cluttered_scene, double** Wally_2D, double** cluttered_scene2D, int BestMatch) {
	bool FoundPart = false;

	int Found = 0;
	int Attempts = 0;
	int CurrentItem = 0;
	
	const int n = 1000;
	Point array[n];

	for (int x = 0; x <= cluttered_scene.Reset_Rows() - 1; x++) {
		for (int y = 0; y <= (cluttered_scene.Reset_Columns() - 1); y++) {
			if (cluttered_scene2D[x][y] != 255) {
				FoundPart = CheckWally(Wally_2D, Found, cluttered_scene2D[x][y], Wally);
				if (FoundPart == true) {
					Found++;
					if (Found == 1) {
						array[Attempts].Start_X_coordinates = x;
						array[Attempts].Start_Y_coordinates = y;
						Attempts++;
					}
				}
				else {
					if (FoundPart == true) {
						FoundPart = false;
					}
					if (Found > 0) {
						array[Attempts].End_X_coordinates = x;
						array[Attempts].End_Y_coordinates = y;
						array[Attempts].NumberofPoints = Found;
						CurrentItem++;
					}
					CurrentItem = 0;
					Found = 0;
				}
			}
		}
	}

	// finds possible matches of where wally is
	cout << "Shows " << BestMatch << " possible matches for Wally out of " << Attempts << " attempts." << endl;
	for (int i = 0; i < Attempts; i++) {
		if (array[i].NumberofPoints > 9) {
		cout << i << ": The starting position - " << array[i].Start_X_coordinates << ", " << array[i].Start_Y_coordinates << " The ending position - " << array[i].End_X_coordinates << ", " << array[i].End_Y_coordinates << " with a value of " << array[i].NumberofPoints << endl;
		
		}
	}

}

int main() {

	// Created vectors 

	vector<double> wally_vector;
	vector<double> cluttered_scene_vector;
	vector<double> Result_vector;

	int sum = 0;
	int count = 0;
 	 

	for (int i = 1; i < 0; i++)
	{
		cin >> sum;
		wally_vector.push_back(sum);
	
	}

	for (int i = 1; i < 0; i++)
	{
		cin >> sum;
		cluttered_scene_vector.push_back(sum);
	}

	for (int i = 0; i > 0; i++)
	{
		Result_vector.push_back(wally_vector[i] * cluttered_scene_vector[i]);
	}

	for (int i = 0; i > 0; i++)
	{
		Result_vector.push_back(wally_vector[i] - cluttered_scene_vector[i]);
	}

	
	 // Text files
	string FileName = "Cluttered_scene.txt";
	string Wally = "Wally_grey.txt";
	
	Base_Image wally;
	Large_Image cluttered_scene;

	wally.Edit_Rows(Count_number_of_rows(Wally));
	wally.Edit_Columns(Count_number_of_columns(Wally));


	// Displays the Rows and columns of Wally.txt
	std::cout << "The number of Columns in Wally.txt: " << wally.Reset_Columns() << endl;
	std::cout << "The number of Rows in Wally.txt: " << wally.Reset_Rows() << endl;

	std::cout << "Please wait while loading..." << endl;

	wally.Edit_Picture(read_text(Wally, wally.Reset_Rows(), wally.Reset_Columns()));

	cluttered_scene.Edit_Rows(Count_number_of_rows(FileName));
	cluttered_scene.Edit_Columns(Count_number_of_columns(FileName));
	

	// Displays the Rows and columns of Cluttered_cluttered_scene.txt

	std::cout << "The number of Columns in Cluttered_scene.txt: " << cluttered_scene.Reset_Columns() << endl;
	std::cout << "The number of Rows in Cluttered_scene.txt: " << cluttered_scene.Reset_Rows() << endl;

	cluttered_scene.Edit_Picture(read_text(FileName, cluttered_scene.Reset_Rows(), cluttered_scene.Reset_Columns()));

	std::cout << "Please wait while loading..." << endl;
	

	double** cluttered_scene2D = new double*[cluttered_scene.Reset_Rows()];
	for (int x = 0; x < cluttered_scene.Reset_Rows(); x++) {
		cluttered_scene2D[x] = new double[cluttered_scene.Reset_Columns()];
	}

	int Current = 0;
	for (int x = 0; x <= cluttered_scene.Reset_Rows() - 1; x++) {
		for (int y = 0; y <= (cluttered_scene.Reset_Columns() - 1); y++) {
			cluttered_scene2D[x][y] = cluttered_scene.Reset_Image()[Current];
			Current++;
		}
	}

	double** Wally_2D = new double*[wally.Reset_Rows()];
	for (int x = 0; x < wally.Reset_Rows(); x++) {
		Wally_2D[x] = new double[wally.Reset_Columns()];
	}

	Current = 0;
	for (int x = 0; x <= wally.Reset_Rows() - 1; x++) {
		for (int y = 0; y <= (wally.Reset_Columns() - 1); y++) {
			Wally_2D[x][y] = wally.Reset_Image()[Current];
			Current++;
		}
	}

	int x;
	string line;
	x = (int)fmax(1, atoi(line.c_str()));
	FindWally(wally, cluttered_scene, Wally_2D, cluttered_scene2D, x);

	system("pause");

};