#include <iostream>
using namespace std;


struct Time {
    int secs;
    int mins;
    int hours;
};


long timeToSecs(Time time);
Time secsToTime(long secs);


int main(void) {

    Time t1, t2, t3;
    char trash;

    cout << "Enter first time in format hh:mm:ss: ";
    cin >> t1.hours >> trash >> t1.mins >> trash >> t1.secs;
    cout << "Enter second time in format hh:mm:ss: ";
    cin >> t2.hours >> trash >> t2.mins >> trash >> t2.secs;

    t3 = secsToTime(timeToSecs(t1) + timeToSecs(t2));
    cout << "Result time: " << t3.hours << ':'
        << t3.mins << ':' << t3.secs << endl;

    return 0;

}


long timeToSecs(Time time) {

    return (time.hours * 3600 + time.mins * 60 + time.secs);

}

Time secsToTime(long secs) {

    Time time;

    time.hours = secs / 3600;
    secs -= time.hours * 3600;
    time.mins = secs / 60;
    time.secs = secs % 60;

    return time;

}
