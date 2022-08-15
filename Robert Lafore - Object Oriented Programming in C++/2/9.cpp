#include <iostream>

using namespace std;

int main(void){

    int a, b, c, d;
    char trash;

    cout << "Enter first fraction (format a/b): ";
    cin >> a >> trash >> b;
    cout << "Enter second fraction (format a/b): ";
    cin >> c >> trash >> d;

    cout << "Result: " << a*d + b*c << '/' << b * d << endl;

    return 0;

}