#include <iostream>
using namespace std;

inline long timeConvert(int h, int m, int s) {

	return (h * 3600 + m * 60 + s);

}

int main(){

	int h, m, s;
	char answer, trash;

	do {

		cout << "Enter time in hh:mm:ss format: ";
		cin >> h >> trash >> m >> trash >> s;
		cout << "This is " << timeConvert(h, m, s) << " seconds\n";

		cout << "Do you want to continue (y/n): ";
		cin >> answer;

	} while (answer == 'y');


	return 0;

}
