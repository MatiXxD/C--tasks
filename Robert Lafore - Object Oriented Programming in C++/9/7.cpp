#include <iostream>
using namespace std;

class Counter {

protected:
    unsigned int count;

public:
    Counter() : count(0) {  }

    Counter(int c) : count(c) {  }

    unsigned int get_count() const {
        return count;
    }

    Counter operator ++ () {
        return Counter(++count);
    }

    Counter operator ++ (int) {
        return Counter(count++);
    }

};

class CountDn : public Counter {

public:
    CountDn() : Counter() { }

    CountDn(int c) : Counter(c) { }

    CountDn operator -- () {
        return CountDn(--count);
    }

    CountDn operator -- (int) {
        return CountDn(count--);
    }

};


int main() {

    CountDn c1 = 5;
    CountDn c2 = --c1;
    CountDn c3 = c1--;

    cout << "c1 = " << c1.get_count() << endl;
    cout << "c2 = " << c2.get_count() << endl;
    cout << "c3 = " << c3.get_count() << endl;

    return 0;

}
