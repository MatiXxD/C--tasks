#include <iostream>
using namespace std;

class Queue{

private:
    static const int MAX = 4;
    int arr[MAX];
    int head;
    int tail;

public:
    Queue() : head(-1), tail(-1) { }

    void put(int val){
        arr[++tail] = val;
        if(tail >= MAX - 1)
            tail = -1;
    }

    int get(){
        int retVal = arr[++head];
        if(head >= MAX - 1)
            head = -1;
        return retVal;
    }

};



int main() {

    Queue q1;

    q1.put(33);
    cout << q1.get() << endl;
    q1.put(44);
    cout << q1.get() << endl;
    q1.put(55);
    cout << q1.get() << endl;
    q1.put(66);
    cout << q1.get() << endl;
    q1.put(33);
    cout << q1.get() << endl;
    q1.put(44);
    cout << q1.get() << endl;
    q1.put(55);
    cout << q1.get() << endl;
    q1.put(66);
    cout << q1.get() << endl;

}
