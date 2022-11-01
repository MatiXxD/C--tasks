#include <iostream>
#include <string>
using namespace std;

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

class Book : private Publication {

private:
	int pages;

public:
	void getData() {
		this->Publication::getData();
		cout << "Enter pages: ";
		cin >> pages;
	}

	void putData() {
		this->Publication::putData();
		cout << "Pages: " << pages << endl;
	}

};

class Tape : private Publication {

private:
	float time;

public:
	void getData() {
		this->Publication::getData();
		cout << "Enter time (in minutes): ";
		cin >> time;
	}

	void putData() {
		this->Publication::putData();
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
