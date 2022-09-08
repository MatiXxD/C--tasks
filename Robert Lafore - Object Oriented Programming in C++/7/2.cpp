#include <iostream>
#include <string>
using namespace std;

class Employee {

private:
	string name;
	long id;

public:
	Employee() : name(), id(0) {}

	void getData() {
		cout << "Enter name: ";	getline(cin, name);
		cout << "Enter id: ";	cin >> id;
	}

	void putData() {
		cout << "Name: " << name << endl
			<< "Id: " << id << endl;
	}

};

int main() {

	const int SIZE = 100;
	Employee employees[SIZE];
	string trash;
	char answer;

	int empCount = 0;
	do {

		cout << "\nEmployee " << empCount << endl;
		employees[empCount++].getData();
		if (empCount >= SIZE) break;

		cout << "Do you want to continue (y / n): ";
		cin >> answer;
		getline(cin, trash);	// get '\n' from buffer

	} while (answer == 'y');

	cout << "\n\nInformation\n";
	for (int i = 0; i < empCount; i++)
		employees[i].putData();

	return 0;

}
