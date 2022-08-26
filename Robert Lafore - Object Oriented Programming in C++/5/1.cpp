#include <iostream>
using namespace std;

float circarea(float radius);

int main(){

	float r;
	cout << "Enter radius: ";
	cin >> r;
	cout << "Circle area: " << circarea(r) << endl;

	return 0;

}

float circarea(float radius) {

	return 3.14159F * radius * radius;

}
