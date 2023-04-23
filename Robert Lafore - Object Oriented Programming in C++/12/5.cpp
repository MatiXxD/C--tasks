#include <iostream>
#include <iomanip>


class Time {

private:
	int secs;
	int mins;
	int hours;


public:
	void get_time();
	void put_time();

};

void Time::get_time() {

	std::cout << "Enter hours: ";
	std::cin >> hours;
	while (std::cin.fail() || hours > 23 || hours < 0) {
		if (std::cin.fail()) {
			std::cout << "Input error. Try again: ";
		}
		else {
			std::cout << "Value should be from 0 to 23. Try again: ";
		}
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> hours;
	}

	std::cout << "Enter minutes: ";
	std::cin >> mins;
	while (std::cin.fail() || mins > 59 || mins < 0) {
		if (std::cin.fail()) {
			std::cout << "Input error. Try again: ";
		}
		else {
			std::cout << "Value should be from 0 to 59. Try again: ";
		}
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> mins;
	}

	std::cout << "Enter seconds: ";
	std::cin >> secs;
	while (std::cin.fail() || secs > 59 || secs < 0) {
		if (std::cin.fail()) {
			std::cout << "Input error. Try again: ";
		}
		else {
			std::cout << "Value should be from 0 to 59. Try again: ";
		}
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> secs;
	}

}

void Time::put_time() {

	std::cout << std::setfill('0') << std::setw(2) << hours
							<< ':' << std::setw(2) << mins
							<< ':' << std::setw(2) << secs;

}




int main() {

	Time t;

	char answer;
	do {
		std::cout << "Entering time\n"; t.get_time();
		std::cout << "Time = "; t.put_time(); std::cout << std::endl;
		std::cout << "Do you want to continue? (y/n): ";
		std::cin >> answer;
	} while (answer == 'y' || answer == 'Y');


	return 0;

}
