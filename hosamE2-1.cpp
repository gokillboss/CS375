#include <iostream>
using namespace std;

int main() {

	int x0, y0, x1, y1;
	cin >> x0 >> y0 >> x1 >> y1;

	float dy = y1 - y0;
	float dx = x1 - x0;



	float m = dy / dx;


	float b = y0 - m * x0;




	// vertical line
	if (x0 == x1) {
		int x = x0;

		for (int y = y0; y <= y1; y++) {
			cout << x << ", " << y << endl;
		}
	}
	else if (y0 == y1) { // horizontal line
		int y = y0;

		for (int x = x0; x <= x1; x++) {
			cout << x << ", " << y << endl;
		}

	}
	else if (abs(dx) >= abs(dy)) {

		// x0 < x1
		if (x0 < x1) {
			for (int x = x0; x <= x1; x++) {

				int y = m * x + b + 0.5;
				cout << x << ", " << y << endl;
			}
		}
		else { // X0 > x1

			for (int x = x0; x >= x1; x--) {

				int y = m * x + b + 0.5;
				cout << x << ", " << y << endl;
			}
		}
	}
	else {
		if (y0 < y1) {
			for (int y = x0; y <= y1; y++) {

				int x = ((y-b)/m) + 0.5;
				cout << x << ", " << y << endl;

			}
		}
		else { // y0 > y1
			for (int y = y0; y >= y1; y--) {

				int x = ((y - b) / m) + 0.5;
				cout << x << ", " << y << endl;

			}
		}
	}
}
