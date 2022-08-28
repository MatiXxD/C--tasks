#include <iostream>
using namespace std;

class Angle{

private:
	short degrs;
	float mins;
	char direc;

public:
	Angle() : degrs(0), mins(0.0F), direc('N') {}

	Angle(short d, float m, char dc) :
		degrs(d), mins(m), direc(dc) {}

	void display() const {
		cout << degrs << '\xF8' << mins << "' " << direc;
	}

	void getAngle();

};

void Angle::getAngle() {

	cout << "Enter direction (N, S, W, E): ";
	cin >> direc;
	while (direc != 'N' && direc != 'S' && direc != 'W' && direc != 'E') {
		cout << "Wrong direction. Try again: ";
		cin >> direc;
	}

	if (direc == 'N' || direc == 'S') {
		cout << "Enter degrees (from 0 to 90): ";
		cin >> degrs;
		while (degrs > 90 || degrs < 0) {
			cout << "Wrong degrees number. Try again: ";
			cin >> degrs;
		}
	}
	else {
		cout << "Enter degrees (from 0 to 180): ";
		cin >> degrs;
		while (degrs > 180 || degrs < 0) {
			cout << "Wrong degrees number. Try again: ";
			cin >> degrs;
		}
	}

	cout << "Enter minutes: ";
	cin >> mins;
	while (mins > 60.0f) {
		cout << "Wrong minutes number. Try again: ";
		cin >> mins;
	}

}


int main() {

	Angle angle(149, 34.8F, 'W');
	cout << "First angle is: ";
	angle.display(); cout << endl;

	char answer;
	do {

		"\nEnter new value: ";
		angle.getAngle();
		cout << "New angle is: "; angle.display();
		cout << endl;

		cout << "Do you want to continue (y/n): ";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}
