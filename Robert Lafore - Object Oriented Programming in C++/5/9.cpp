#include <iostream>
using namespace std;


struct Time {
	int hours;
	int mins;
	int secs;
};


void displayTime(Time t);
void swap(Time& t1, Time& t2);


int main() {

	Time t1 = { 11, 30, 12 };
	Time t2 = { 21, 15, 49 };

	cout << "Before swap:\n";
	cout << "t1 = "; displayTime(t1);
	cout << "t2 = "; displayTime(t2);

	swap(t1, t2);

	cout << "\nAfter swap:\n";
	cout << "t1 = "; displayTime(t1);
	cout << "t2 = "; displayTime(t2);

	return 0;

}


void displayTime(Time t) {

	cout << t.hours << ':' << t.mins << ':' << t.secs << endl;

}

void swap(Time& t1, Time& t2) {

	Time temp = t1;
	t1 = t2;
	t2 = temp;

}
