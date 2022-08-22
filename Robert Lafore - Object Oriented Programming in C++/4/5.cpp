#include <iostream>
using namespace std;


struct Date{
	int day;
	int month;
	int year;
};


int main() {

	Date date;
	char trash;

	cout << "Enter date in format dd/mm/yy: ";
	cin >> date.day >> trash >> date.month >> trash >> date.year;

	cout << "Day: " << date.day << endl
		<< "Month: " << date.month << endl
		<< "Year: " << date.year << endl;

	return 0;

}
