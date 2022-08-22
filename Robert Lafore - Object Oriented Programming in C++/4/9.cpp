#include <iostream>
using namespace std;

struct Time {
    int secs;
    int mins;
    int hours;
};

int main(void) {

    Time t1;
    char trash;

    cout << "Enter time in format hh:mm:ss: ";
    cin >> t1.hours >> trash >> t1.mins >> trash >> t1.secs;

    long totalSecs = t1.hours * 3600 + t1.mins * 60 + t1.secs;
    cout << "Seconds: " << totalSecs << endl;

    return 0;

}
