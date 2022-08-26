#include <iostream>
using namespace std;


struct Distance {
	int feet;
	float inches;
};


inline void engldisp(Distance dd) {
	cout << dd.feet << "\'-" << dd.inches << "\"";
}

Distance getBiggerDistance(Distance d1, Distance d2);



int main() {

	Distance d1, d2;

	cout << "Enter feet: ";
	cin >> d1.feet;
	cout << "Enter inches: ";
	cin >> d1.inches;
	cout << "Enter feet: ";
	cin >> d2.feet;
	cout << "Enter inches: ";
	cin >> d2.inches;

	cout << "Largest is ";
	engldisp(getBiggerDistance(d1, d2));

	return 0;

}


Distance getBiggerDistance(Distance d1, Distance d2) {

	if (d1.feet > d2.feet)	return d1;
	if (d1.feet < d2.feet)	return d2;

	if (d1.inches > d2.inches)	return d1;
	else						return d2;

}
