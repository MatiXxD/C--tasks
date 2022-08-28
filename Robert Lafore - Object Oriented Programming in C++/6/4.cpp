#include <iostream>
using namespace std;


class Employee {

private:
	int id;
	float compensation;

public:
	Employee() : id(0), compensation(0.0F){}

	void getEmployee() {
		cout << "Enter id: ";
		cin >> id;
		cout << "Enter compensation: ";
		cin >> compensation;
	}

	void display() const {
		cout << "Employee " << id << " and his compensation is "
			<< compensation << endl;
	}

};


int main() {

	Employee man1, man2, man3;

	man1.getEmployee();
	man2.getEmployee();
	man3.getEmployee();

	cout << "\nEmployees information:\n";
	man1.display();
	man2.display();
	man3.display();

	return 0;

}
