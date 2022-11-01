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

class Publication {

private:
	string name;
	float price;

public:
	void getData() {
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter price: ";
		cin >> price;
	}

	void putData() {
		cout << "Book: " << name << endl;
		cout << "Price: " << price << endl;
	}

};

class Publication2 : public Publication {

private:
	Date date;

public:
	void getData() {
		Publication::getData();
		date.getDate();
	}

	void putData() {
		Publication::putData();
		cout << "Date: "; date.display(); cout << endl;
	}


};

class Book : private Publication2 {

private:
	int pages;

public:
	void getData() {
		this->Publication2::getData();
		cout << "Enter pages: ";
		cin >> pages;
	}

	void putData() {
		this->Publication2::putData();
		cout << "Pages: " << pages << endl;
	}

};

class Tape : private Publication2 {

private:
	float time;

public:
	void getData() {
		this->Publication2::getData();
		cout << "Enter time (in minutes): ";
		cin >> time;
	}

	void putData() {
		this->Publication2::putData();
		cout << "Time (in minutes): " << time << endl;
	}

};


int main() {

	char answer;

	do {

		char type;
		cout << "Enter 'b' for book and 't' for tape: ";
		cin >> type;

		if (type == 'b') {
			Book b;
			b.getData(); cout << endl;
			b.putData(); cout << endl;
		}
		else if (type == 't') {
			Tape t;
			t.getData(); cout << endl;
			t.putData(); cout << endl;
		}
		else
			cout << "Wrong input" << endl;

		cout << "Do you want to continue? (y / n):";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}
