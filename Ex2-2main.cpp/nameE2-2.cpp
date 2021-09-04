/************************************************************************************************/
/* Program:                                                                                     */
/* Author: Dr. Watts                                                                            */
/* Modified by:                                                                                 */
/* Date:                                                                                        */
/* Description:                                                                                 */
/************************************************************************************************/

#include <iostream>
#include <fstream>
#include "Bitmap_Image.hpp"
using namespace std;

// Function Prototypes

void DrawLine (bitmap_image & bmp, int x1, int y1, int x2, int y2, int red, int green, int blue);

/************************************************************************************************/
/* Function: main                                                                               */
/* Arguments:                                                                                   */
/* Description:                                                                                 */
/************************************************************************************************/

int main (int argc, char * argv [])
{
	if (argc < 3)
	{
		cerr << "Usage: " << argv[0] << " <input_file> <bitmap_file>\n";
		exit (1);
	}
	ifstream input (argv[1]);
	if (input.fail())
	{
		cerr << "File: " << argv[1] << " cannot be opened.\n";
		exit (2);
	}
	int width, height;
	input >> width >> height;
	bitmap_image bitmap = bitmap_image (width+1, height+1);
	if (bitmap.failed())
	{
		cerr << "Bitmap could not be created\n";
		exit (3);
	}
	bitmap.clear(0xFF);
	int r = 0, g = 0, b = 0;
	input >> r >> g >> b;
	int x1, y1, x2, y2;
	while (input >> x1 >> y1 >> x2 >> y2)
	{
		cout << "Drawing line from (" << x1 << ',' << y1 
		     << ") to (" << x2 << ',' << y2 << ")\n";
		DrawLine (bitmap, x1, y1, x2, y2, r, g, b);
	}
	input.close();
	bitmap.save_image (argv[2]);
	if (bitmap.failed())
	{
		cerr << "Bitmap could not be saved\n";
		exit (4);
	}
	return 0;
}

/************************************************************************************************/
/* Function: DrawLine                                                                           */
/* Arguments:                                                                                   */
/* Description:                                                                                 */
/************************************************************************************************/

void DrawLine(bitmap_image & bmp, int x1, int y1, int x2, int y2, int red, int green, int blue) {


	float dy = y2 - y1;
	float dx = x2 - x1;
	float m = dy / dx;
	float b = y1 - m * x1;



	if (x1 == x2) { // verical line
		int x = x1;

		for (int y = y1; y <= y2; y++) {
			cout << x << ", " << y << endl;
		}
	}
	else if (y1 == y2) {  // herizontal line
		int y = y1;

		for (int x = x1; x <= x2; x++) {
			cout << x << ", " << y << endl;
		}
	}
	else if (abs(dx) >= abs(dy)) {

		// x1 < x2
		if (x1 < x2) {
			for (int x = x1; x <= x2; x++) {

				int y = m * x + b + 0.5;
				cout << x << ", " << y << endl;
			}
		}
		else { // X1 > x2

			for (int x = x1; x >= x2; x--) {

				int y = m * x + b + 0.5;
				cout << x << ", " << y << endl;
			}
		}
	}
	else {
		if (y1 < y2) {
			for (int y = y1; y <= y2; y++) {

				int x = ((y - b) / m) + 0.5;
				cout << x << ", " << y << endl;

			}
		}
		else { // y1 > y2
			for (int y = y1; y >= y2; y--) {

				int x = ((y - b) / m) + 0.5;
				cout << x << ", " << y << endl;

			}
		}
	}


		bmp.set_pixel(x1, y1, red, green, blue);
		bmp.set_pixel(x2, y2, red, green, blue);
}