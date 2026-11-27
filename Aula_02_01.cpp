
#include <iostream>

#include <fstream>

using namespace std;



int main() {
	ofstream image;

	image.open("image/Outputs/ppm_Image_For_blue.ppm");


	if (image.is_open())
	{
		// Header Images !!
		image << "P3" << endl;
		image << "100 50" << endl;
		image << "255" << endl;


		// Body Images !!
		//image << "255 0 0" << endl; // RGB= RED
		//image << "0 255 0" << endl; // RGB= GREEN 
		//image << "0 0 255" << endl; // RGB= BLUE 
		//image << "255 255 0" << endl; // RGB= YELLOW 
		//image << "255 255 255" << endl; // RGB= WHITE 
		//image << "0 0 0" << endl;	// RGB= BLACK 

		/*for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 50; x++) {
				
				image << "255 0 0\n";

				if (x > 25) {

				}
			}
		}*/

		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 50; x++) {
				if (x < 25) {
					image << y <<" " << "255 255\n";
				}
				else {
					image << x << " " << y <<" " << "0\n";
				}
			}
		}


	}


	image.close();




	return 0;
}