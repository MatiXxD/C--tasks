#include <iostream>
#include <iomanip>
using namespace std;


struct Employee{
	int id;
	float compensation;
};


int main() {

	Employee man1, man2, man3;

	cout << "Enter id and compensation for each of three man.\n";
	cin >> man1.id >> man1.compensation
	    >> man2.id >> man2.compensation
		>> man3.id >> man3.compensation;

	cout << setw(6) << "Id" << setw(15) << "Compensation\n"
		<< setw(6) << man1.id << setw(13) << man1.compensation << "$\n"
		<< setw(6) << man2.id << setw(13) << man2.compensation << "$\n"
		<< setw(6) << man3.id << setw(13) << man3.compensation << "$\n";

	return 0;

}
