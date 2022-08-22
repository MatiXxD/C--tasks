#include <iostream>
using namespace std;

struct Time {
    int secs;
    int mins;
    int hours;
};

int main(void) {

    Time t1, t2, t3;
    char trash;

    cout << "Enter first time in format hh:mm:ss: ";
    cin >> t1.hours >> trash >> t1.mins >> trash >> t1.secs;
    cout << "Enter second time in format hh:mm:ss: ";
    cin >> t2.hours >> trash >> t2.mins >> trash >> t2.secs;

    long totalSecs = (t1.hours + t2.hours) * 3600 + (t1.mins + t2.mins) * 60 + (t1.secs + t2.secs);
    t3.hours = totalSecs / 3600;
    totalSecs -= t3.hours * 3600;
    t3.mins = totalSecs / 60;
    t3.secs = totalSecs % 60;

    cout << "Result time: " << t3.hours << ':'
        << t3.mins << ':' << t3.secs << endl;

    return 0;

}
