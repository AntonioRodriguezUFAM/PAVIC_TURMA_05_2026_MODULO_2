
#include <iostream>


#include <fstream>

using namespace std;



int main() {
	ofstream image;
	ifstream image_1;

	image_1.open("image/Input.ppm");
	image.open("image/Outputs/Imput_copy.ppm");


	string type = "", width = "", height = "", RGB = "";

	// Copy to Memory
	image_1 >> type;
	cout << type << endl;
	image_1 >> width;
	cout << width<<" ";
	image_1 >> height;
	cout << height << endl;
	image_1 >> RGB;
	cout << RGB << endl;
	
	// Copy Header to New Image
	image << type<<endl;
	image << width << " "<< height<<endl;
	image << RGB << endl;
	


	string Red = "", Green = "", Blue = "";

	while (!image_1.eof()) {

		image_1 >> Red;
		image_1 >> Green;
		image_1 >> Blue;

		//cout << Red << " " << Green << " " << Blue << endl;

		image << Red << " ";
		image << Green<< " ";
		image << Blue << " ";




	}
	

	




	
	//if (image.is_open())
	//{
	//	// Header Images !!
	//	image << "P3" << endl;
	//	image << "100 50" << endl;
	//	image << "255" << endl;


	//	// Body Images !!
	//	//image << "255 0 0" << endl; // RGB= RED
	//	//image << "0 255 0" << endl; // RGB= GREEN 
	//	//image << "0 0 255" << endl; // RGB= BLUE 
	//	//image << "255 255 0" << endl; // RGB= YELLOW 
	//	//image << "255 255 255" << endl; // RGB= WHITE 
	//	//image << "0 0 0" << endl;	// RGB= BLACK 

	//	/*for (int y = 0; y < 100; y++) {
	//		for (int x = 0; x < 50; x++) {

	//			image << "255 0 0\n";

	//			if (x > 25) {

	//			}
	//		}
	//	}*/

	//	for (int y = 0; y < 100; y++) {
	//		for (int x = 0; x < 50; x++) {
	//			if (x < 25) {
	//				image << y << " " << "255 255\n";
	//			}
	//			else {
	//				image << x << " " << y << " " << "0\n";
	//			}
	//		}
	//	}


	//}


	image.close();
	image_1.close();




	return 0;
}