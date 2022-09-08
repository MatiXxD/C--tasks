#include <iostream>
using namespace std;

class Distance {

private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {  }

    Distance(int ft, float in) : feet(ft), inches(in) {  }

    void getDist() {
        cout << "\nEnter feet: ";  cin >> feet;
        cout << "Enter inches: ";  cin >> inches;
    }

    void showDist() {
        cout << feet << "\'-" << inches << '\"';
    }

    void addDist(Distance, Distance);

    void getAverage(Distance, int);

};

void Distance::addDist(Distance d2, Distance d3){

    inches = d2.inches + d3.inches;
    feet = 0;
    if (inches >= 12.0) {
        inches -= 12.0;
        feet++;
    }
    feet += d2.feet + d3.feet;

}

void Distance::getAverage(Distance total, int count) {

    float temp = total.feet + total.inches / 12.0f;
    temp /= count;
    feet = (int)temp;
    inches = (temp - feet) * 12.0f;

}


int main() {

    const int SIZE = 100;
    Distance distArray[SIZE];
    char answer;

    int distCount = 0;
    do {

        cout << "Distance " << distCount << endl;
        distArray[distCount++].getDist();
        if (distCount >= SIZE) break;

        cout << "Do you want to continue (y / n): ";
        cin >> answer;

    } while (answer == 'y');

    Distance total, average;
    for (int i = 0; i < distCount; i++)
        total.addDist(total, distArray[i]);
    average.getAverage(total, distCount);

    cout << "Average distance:"; average.showDist();

    return 0;

}
