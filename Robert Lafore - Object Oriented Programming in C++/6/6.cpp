#include <iostream>
#include <iomanip>
using namespace std;


enum Etype {
	laborer, secretary, manager,
	accountant, executive, researcher
};


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


class Employee {

private:
	int id;
	float compensation;
	Etype type;
	Date date;

public:
	Employee() : id(0), compensation(0.0F), type(laborer), date() {}
	void getEmployee();
	void display() const;

};

void Employee::getEmployee() {

	char chType;

	cout << "Enter id: ";
	cin >> id;

	cout << "Enter compensation: ";
	cin >> compensation;

	cout << "Enter employee type (first letter only)\n"
		<< "laborer, secretary, manager,\n"
		<< "accountant, executive, researcher): ";
	cin >> chType;
	switch (chType) {
	case 'l':	type = laborer;		break;
	case 's':	type = secretary;	break;
	case 'm':	type = manager;		break;
	case 'a':	type = accountant;	break;
	case 'e':	type = executive;	break;
	case 'r':	type = researcher;	break;
	default:	type = laborer;		break;
	}

	date.getDate();

}

void Employee::display() const {

	cout << "Employee " << id << endl;
	cout << "Compensation is " << compensation << endl;
	cout << "Employee type is ";
	switch (type) {
	case laborer:		cout << "laborer.\n";		break;
	case secretary:		cout << "secretary.\n";		break;
	case manager:		cout << "manager.\n";		break;
	case accountant:	cout << "accountant.\n";	break;
	case executive:		cout << "executive.\n";		break;
	case researcher:	cout << "researcher.\n";	break;
	}
	cout << "Date of first employment ";  date.display();
	cout << endl;

}


int main() {

	Employee man1, man2, man3;

	man1.getEmployee();
	man2.getEmployee();
	man3.getEmployee();

	cout << "\nEmployees information:\n";
	man1.display(); cout << endl;
	man2.display(); cout << endl;
	man3.display(); cout << endl;

	return 0;

}
