#include <iostream>
#include <string>
using namespace std;

class Publication {

private:
	string name;
	float price;

public:
	virtual void getData() {
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter price: ";
		cin >> price;
	}

	virtual void putData() {
		cout << "Book: " << name << endl;
		cout << "Price: " << price << endl;
	}

	virtual bool isOversized() = 0;

};

class Book : public Publication {

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

	bool isOversized() {

		return pages > 800 ? true : false;

	}

};

class Tape : public Publication {

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

	bool isOversized() {

		return time > 90 ? true : false;

	}

};


int main() {

	const int MAX_SIZE = 100;
	Publication* array[MAX_SIZE];

	int n = 0;
	char answer;
	do {

		char type;
		cout << "Enter 'b' for book and 't' for tape: ";
		cin >> type;

		if (type == 'b') {
			array[n] = new Book;
			array[n]->getData(); cout << endl;
		}
		else if (type == 't') {
			array[n] = new Tape;
			array[n]->getData(); cout << endl;
		}
		else {
			cout << "Wrong input" << endl;
		}

		n++;
		cout << "Do you want to continue? (y / n):";
		cin >> answer;

	} while (answer == 'y');

	cout << "\nOUTPUT:\n";
	for (int i = 0; i < n; i++) {
		array[i]->putData();
		if (array[i]->isOversized())
			std::cout << "OVERSIZED!\n";
		cout << endl;
	}

	return 0;

}
