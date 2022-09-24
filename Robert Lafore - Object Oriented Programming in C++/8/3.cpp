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

	Time operator +(Time t2) const;

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

	const Time t1(11, 31, 45), t2(8, 28, 30);
	Time t3;

	t3 = t1 + t2;

	t1.display(); cout << " + ";
	t2.display(); cout << " = ";
	t3.display(); cout << endl;

	return 0;

}
