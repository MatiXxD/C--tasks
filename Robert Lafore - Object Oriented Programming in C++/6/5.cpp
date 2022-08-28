#include <iostream>
#include <iomanip>
using namespace std;

class Date {

private:
	short day;
	short month;
	short year;

public:
	Date() : day(1), month(1), year(1) {}

	void getDate() {
		char trash;
		cout << "Enter date in dd/mm/yy format: ";
		cin >> day >> trash >> month >> trash >> year;
	}

	void display() const {
		cout << setfill('0');
		cout << setw(2) << day << '/' << setw(2) << month
			<< '/' << setw(2) << year;
		cout << setfill(' ');
	}

};


int main() {

	Date date;
	date.getDate();

	cout << "You entered this date: ";
	date.display();

	return 0;

}
