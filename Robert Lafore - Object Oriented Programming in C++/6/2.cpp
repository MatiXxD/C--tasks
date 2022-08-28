#include <iostream>
#include <conio.h>
using namespace std;

class TollBooth {

private:
	unsigned carCount;
	double totalMoney;

public:
	TollBooth() : carCount(0), totalMoney(0.0) {}

	void payingCar() {
		carCount++;
		totalMoney += 0.5;
	}

	void nopayCar() {
		carCount++;
	}

	void display() const {
		cout << "Car amount: " << carCount << endl;
		cout << "Money amount: " << totalMoney << endl;
	}

};

int main() {

	TollBooth tollBooth;
	char ch;

	cout << "Enter 'p' to pay or 'n' not to pay (Esc to stop):\n";
	while ((ch = _getch()) != '\x1B') {
		if (ch == 'p')
			tollBooth.payingCar();
		else if (ch == 'n')
			tollBooth.nopayCar();
	}
	tollBooth.display();

	return 0;

}
