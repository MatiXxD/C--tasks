#include <iostream>
using namespace std;


struct Distance{
	int feet;
	float inches;
};

struct Volume {
	Distance x;
	Distance y;
	Distance z;
};


int main() {

	Volume volume = { {13, 6.5}, {10, 5.5}, {11, 7.25} };

	float lx = volume.x.feet + volume.x.inches / 12.0f;
	float ly = volume.y.feet + volume.y.inches / 12.0f;
	float lz = volume.z.feet + volume.z.inches / 12.0f;

	cout << "Volume is " << lx * ly * lz << " feet^3.\n";

	return 0;

}
