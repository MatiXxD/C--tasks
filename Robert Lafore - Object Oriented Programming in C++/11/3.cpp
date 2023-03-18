#include <iostream>
using namespace std;

class Distance {

private:
    int feet;
    float inches;

public:
    void showdist() {
        cout << feet << "\'-" << inches << '\"';
    }

    Distance() : feet(0), inches(0.0){}

    Distance(int ft, float in) : feet(ft), inches(in){}

    Distance(float val) {
        feet = static_cast<int>(val);
        inches = (val - feet) * 12.0;
    }

    friend Distance operator *(Distance d1, Distance d2);

};

Distance operator *(Distance d1, Distance d2) {

    float flt1 = d1.feet + d1.inches / 12;
    float flt2 = d2.feet + d2.inches / 12;

    return Distance(flt1 * flt2);

}

int main() {

    Distance dist1(3, 6.0);
    Distance dist2(2, 3.0);
    Distance dist3;

    dist3 = dist1 * dist2;

    dist3 = 10.0f * dist3;

    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << "\ndist3 = "; dist3.showdist();
    cout << endl;

    return 0;

}
