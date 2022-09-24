#include <iostream>
#include <cmath>
using namespace std;

class Polar {

private:
	static const double PI;
	double r;
	double phi;

public:
	Polar() : r(0), phi(0) {}

	Polar(int radius, int angle) : r(radius), phi(angle) {}

	void Display() {
		cout << "r=" << r << ' ' << "phi=" << phi;
	}

	void SetCoord(int radius, int angle) {
		r = radius;
		phi = angle;
	}

	Polar ConvertToPolar(double x, double y) {
		return Polar(sqrt(x * x + y * y), 180 / PI * atan(y / x));
	}

	Polar operator + (Polar c2) {

		double x1 = r * cos(phi * PI / 180), x2 = c2.r * cos(phi * PI / 180);
		double y1 = r * sin(phi * PI / 180), y2 = c2.r * sin(phi * PI / 180);

		return ConvertToPolar(x1 + x2, y1 + y2);

	}

};

const double Polar::PI = 3.14159265;

int main() {

	Polar c1, c2;
	double phi, rad;

	cout << "First coordinate\n";
	cout << "Radius: "; cin >> rad;
	cout << "Angle: "; cin >> phi;
	c1.SetCoord(rad, phi);

	cout << "\nSecond coordinate\n";
	cout << "Radius: "; cin >> rad;
	cout << "Angle: "; cin >> phi;
	c2.SetCoord(rad, phi);

	Polar c3 = c1 + c2;
	cout << "\nResult\n";
	c3.Display(); cout << endl;

	return 0;

}
