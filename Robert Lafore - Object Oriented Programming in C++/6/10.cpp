#include <iostream>
using namespace std;

class Angle {

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

class Ship {

private:
	static int totalCount;
	int shipNum;
	Angle latitude;
	Angle longitude;

public:
	Ship() : latitude(), longitude() {
		shipNum = ++totalCount;
	}

	void getPosition() {
		cout << "Enter latitude (N, S)\n";
		latitude.getAngle();	cout << endl;
		cout << "Enter longitude (W, E)\n";
		longitude.getAngle();	cout << endl;
	}

	void displayInfo() const {
		cout << "Ship number " << shipNum << endl;
		cout << "Latitude: ";	latitude.display();		cout << endl;
		cout << "Longitude: ";	longitude.display();	cout << endl;
		cout << endl;
	}

	void getShipNum() const {
		cout << shipNum;
	}

};

int Ship::totalCount = 0;


int main() {

	Ship ship1, ship2, ship3;

	cout << "Ship "; ship1.getShipNum(); cout << endl;
	ship1.getPosition();
	cout << endl;
	cout << "Ship "; ship2.getShipNum(); cout << endl;
	ship2.getPosition();
	cout << endl;
	cout << "Ship "; ship3.getShipNum(); cout << endl;
	ship3.getPosition();
	cout << endl;

	cout << "\nShips information\n";
	ship1.displayInfo();
	ship2.displayInfo();
	ship3.displayInfo();

	return 0;

}
