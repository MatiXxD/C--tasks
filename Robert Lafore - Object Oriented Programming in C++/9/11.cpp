#include <iostream>
using namespace std;
#include <process.h>

struct mypair {
    int x;
    int y;
};

class Stack{

protected:
    static const int MAX = 10;
    int st[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int var) {
        st[++top] = var;
    }

    int pop() {
        return st[top--];
    }

};

class Stack2 : private Stack {

public:
    void push(int var) {
        if (top >= MAX - 1) {
            cout << "\nError: stack is full"; exit(1);
        }
        Stack::push(var);
    }

    int pop() {
        if (top < 0) {
            cout << "\nError: stack is empty\n"; exit(1);
        }
        return Stack::pop();
    }

};


class StackPair : private Stack2 {

public:
    void push(mypair val) {
        Stack2::push(val.x);
        Stack2::push(val.y);
    }

    mypair pop() {
        mypair temp;
        temp.y = Stack2::pop();
        temp.x = Stack2::pop();
        return temp;
    }

};


int main() {

    StackPair s1;

    s1.push({1, 2});
    s1.push({3, 4});
    s1.push({5, 6});

    mypair out;
    out = s1.pop();
    cout << out.x << ' ' << out.y << endl;
    out = s1.pop();
    cout << out.x << ' ' << out.y << endl;
    out = s1.pop();
    cout << out.x << ' ' << out.y << endl;
    cout << endl;

    return 0;

}
