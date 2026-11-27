
#include <iostream>

#include <fstream>

using namespace std;



int main() {
	ofstream image;

	image.open("image/Outputs/ppm_Image.ppm");


	if (image.is_open())
	{
		// Header Images !!
		image << "P3" << endl;
		image << "3 2" << endl;
		image << "255" << endl;


		// Body Images !!
		image << "255 0 0" << endl; // RGB= RED
		image << "0 255 0" << endl; // RGB= GREEN 
		image << "0 0 255" << endl; // RGB= BLUE 
		image << "255 255 0" << endl; // RGB= YELLOW 
		image << "255 255 255" << endl; // RGB= WHITE 
		image << "0 0 0" << endl;	// RGB= BLACK 

	}


	image.close();




	return 0;
}