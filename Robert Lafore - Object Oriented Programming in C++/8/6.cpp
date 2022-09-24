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

	Time convertToTime(float time) const {

		short h = time / 3600;
		time -= h * 3600;
		short m = time / 60;
		time -= m * 60;
		short s = time;

		return Time(h, m, s);

	}

	Time operator + (Time t2) const;
	Time operator - (Time t2) const;
	Time operator * (float f) const;
	Time operator / (float f) const;

};

Time Time::operator + (Time t2) const {

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

Time Time::operator - (Time t2) const {

	Time t3;

	t3.secs = secs - t2.secs;
	if (t3.secs < 0) {
		t3.mins--;
		t3.secs += 60;
	}
	t3.mins += mins - t2.mins;
	if (t3.mins < 0) {
		t3.hours--;
		t3.mins += 60;
	}
	t3.hours += hours - t2.hours;

	return t3;

}

Time Time::operator * (float f) const {

	float time = secs + 60 * mins + 3600 * hours;
	time *= f;

	return convertToTime(time);

}

Time Time::operator / (float f) const {

	if (f == 0.0f) {
		cout << "Can't divide by zero.\n";
		return Time();
	}

	float time = secs + 60 * mins + 3600 * hours;
	time /= f;

	return convertToTime(time);

}



int main() {

	Time t1(11, 31, 45), t2(8, 28, 30);
	Time t3;
	float f = 2.0f;

	cout << "Time1: "; t1.display(); cout << endl;
	cout << "Time2: "; t2.display(); cout << endl;

	t3 = t1 + t2;
	cout << "t1 + t2: "; t3.display(); cout << endl;

	t3 = t1 - t2;
	cout << "t1 - t2: "; t3.display(); cout << endl;

	t3 = t1 * f;
	cout << "t1 * " << f << " : "; t3.display(); cout << endl;

	t3 = t2 / f;
	cout << "t2 / " << f << " : "; t3.display(); cout << endl;

	return 0;

}
