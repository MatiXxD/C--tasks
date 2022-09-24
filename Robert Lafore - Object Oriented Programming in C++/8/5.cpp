#include <iostream>
#include <iomanip>
using namespace std;


class Time {

private:
	short hours;
	short mins;
	short secs;

public:
	Time() : hours(0), mins(0), secs(0) { }

	Time(short h, short m, short s) : hours(h), mins(m), secs(s) {}

	void display() const {
		cout << setfill('0');
		cout << setw(2) << hours << ':' << setw(2) <<
			setw(2) << mins << ':' << setw(2) << secs;
		cout << setfill(' ');
	}

	Time operator + (Time t2) const;

	Time operator ++ () {

		++secs;
		if (secs >= 60) {
			++mins;
			secs -= 60;
		}
		if (mins >= 60) {
			++hours;
			mins -= 60;
		}

		return Time(hours, mins, secs);

	}

	Time operator ++ (int) {

		Time temp(hours, mins, secs);

		secs++;
		if (secs >= 60) {
			mins++;
			secs -= 60;
		}
		if (mins >= 60) {
			hours++;
			mins -= 60;
		}

		return temp;

	}

	Time operator -- () {

		--secs;
		if (secs < 0) {
			--mins;
			secs += 60;
		}
		if (mins < 0) {
			--hours;
			mins += 60;
		}

		return Time(hours, mins, secs);

	}

	Time operator -- (int) {

		Time temp(hours, mins, secs);

		secs--;
		if (secs < 0) {
			mins--;
			secs += 60;
		}
		if (mins < 0) {
			hours--;
			mins += 60;
		}

		return temp;

	}

};

Time Time::operator +(Time t2) const {

	Time t3;

	t3.secs = secs + t2.secs;
	if (t3.secs >= 60) {
		t3.mins++;
		t3.secs -= 60;
	}
	t3.mins += mins + t2.mins;
	if (t3.mins >= 60) {
		t3.hours++;
		t3.mins -= 60;
	}
	t3.hours += hours + t2.hours;

	return t3;

}


int main() {

	Time t1(11, 31, 45), t2(8, 28, 30);
	Time t3;

	cout << "Time1: "; t1.display(); cout << endl;
	cout << "Time2: "; t2.display(); cout << endl;
	cout << "Time3: "; t3.display(); cout << endl;
	cout << endl;

	t3 = ++t1;
	cout << "Time1: "; t1.display(); cout << endl;
	cout << "Time2: "; t2.display(); cout << endl;
	cout << "Time3: "; t3.display(); cout << endl;
	cout << endl;

	t3 = t2++;
	cout << "Time1: "; t1.display(); cout << endl;
	cout << "Time2: "; t2.display(); cout << endl;
	cout << "Time3: "; t3.display(); cout << endl;
	cout << endl;

	t3 = --t1;
	cout << "Time1: "; t1.display(); cout << endl;
	cout << "Time2: "; t2.display(); cout << endl;
	cout << "Time3: "; t3.display(); cout << endl;
	cout << endl;

	t3 = t2--;
	cout << "Time1: "; t1.display(); cout << endl;
	cout << "Time2: "; t2.display(); cout << endl;
	cout << "Time3: "; t3.display(); cout << endl;
	cout << endl;

	return 0;

}
