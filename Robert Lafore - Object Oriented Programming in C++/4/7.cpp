#include <iostream>
using namespace std;


enum Etype {
	laborer, secretary, manager,
	accountant, executive, researcher
};

struct Date {
	int day;
	int month;
	int year;
};

struct Employee {
	int id;
	float compensation;
	Date date;
	Etype type;
};


int main() {

	Employee man1, man2, man3;
	char type, trash;

	cout << "First man\n";
	cout << "Enter man's id and compensation: ";
	cin >> man1.id >> man1.compensation;
	cout << "Now enter date (dd/mm/yy): ";
	cin >> man1.date.day >> trash >> man1.date.month >> trash >> man1.date.year;
	cout << "Enter man's type: ";
	cin >> type;
	switch (type) {
		case 'l':	man1.type = laborer;		break;
		case 's':	man1.type = secretary;	break;
		case 'm':	man1.type = manager;		break;
		case 'a':	man1.type = accountant;	break;
		case 'e':	man1.type = executive;	break;
		case 'r':	man1.type = researcher;	break;
		default:	exit(1);								break;
	}
	cout << "Second man\n";
	cout << "Enter man's id and compensation: ";
	cin >> man2.id >> man2.compensation;
	cout << "Now enter date (dd/mm/yy): ";
	cin >> man2.date.day >> trash >> man2.date.month >> trash >> man2.date.year;
	cout << "Enter man's type: ";
	cin >> type;
	switch (type) {
		case 'l':	man2.type = laborer;		break;
		case 's':	man2.type = secretary;	break;
		case 'm':	man2.type = manager;		break;
		case 'a':	man2.type = accountant;	break;
		case 'e':	man2.type = executive;	break;
		case 'r':	man2.type = researcher;	break;
		default:	exit(1);								break;
	}
	cout << "Third man\n";
	cout << "Enter man's id and compensation: ";
	cin >> man3.id >> man3.compensation;
	cout << "Now enter date (dd/mm/yy): ";
	cin >> man3.date.day >> trash >> man3.date.month >> trash >> man3.date.year;
	cout << "Enter man's type: ";
	cin >> type;
	switch (type) {
		case 'l':	man3.type = laborer;		break;
		case 's':	man3.type = secretary;	break;
		case 'm':	man3.type = manager;		break;
		case 'a':	man3.type = accountant;	break;
		case 'e':	man3.type = executive;	break;
		case 'r':	man3.type = researcher;	break;
		default:	exit(1);								break;
	}

	cout << "\nFirst man\n" << man1.id << ' ' << man1.compensation << ' '
		<< man1.date.day << '/' << man1.date.month << '/' << man1.date.year << ' ';
	switch (man1.type) {
		case laborer:		cout << "laborer.\n";				break;
		case secretary:		cout << "secretary.\n";		break;
		case manager:		cout << "manager.\n";				break;
		case accountant:	cout << "accountant.\n";	break;
		case executive:		cout << "executive.\n";		break;
		case researcher:	cout << "researcher.\n";	break;
	}
	cout << "Second man\n" << man2.id << ' ' << man2.compensation << ' '
		<< man2.date.day << '/' << man2.date.month << '/' << man2.date.year << ' ';
	switch (man2.type) {
		case laborer:		cout << "laborer.\n";				break;
		case secretary:		cout << "secretary.\n";		break;
		case manager:		cout << "manager.\n";				break;
		case accountant:	cout << "accountant.\n";	break;
		case executive:		cout << "executive.\n";		break;
		case researcher:	cout << "researcher.\n";	break;
	}
	cout << "Third man\n" << man3.id << ' ' << man3.compensation << ' '
		<< man3.date.day << '/' << man3.date.month << '/' << man3.date.year << ' ';
	switch (man3.type) {
		case laborer:		cout << "laborer.\n";				break;
		case secretary:		cout << "secretary.\n";		break;
		case manager:		cout << "manager.\n";				break;
		case accountant:	cout << "accountant.\n";	break;
		case executive:		cout << "executive.\n";		break;
		case researcher:	cout << "researcher.\n";	break;
	}

	return 0;

}
