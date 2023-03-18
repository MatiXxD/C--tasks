#include <iostream>
using namespace std;

class Array {

private:
    int* ptr;
    int size;

public:
    Array(int s) {
        size = s;
        ptr = new int[s];

        for (int i = 0; i < size; i++) {
            ptr[i] = 0;
        }

    }

    ~Array() {
        delete[] ptr;
    }

    int& operator [] (int j){
        return *(ptr + j);
    }

    Array& operator = (const Array&);
    Array(const Array&);

    void print();

};

Array::Array(const Array& arr) {

    size = arr.size;
    ptr = new int[size];

    for (int i = 0; i < size; i++) {
        ptr[i] = arr.ptr[i];
    }

}

Array& Array::operator=(const Array& arr) {

    int min = size <= arr.size ? size : arr.size;

    for (int i = 0; i < min; i++) {
        ptr[i] = arr.ptr[i];
    }

    return *this;

}

void Array::print() {

    for (int i = 0; i < size; i++) {
        cout << ptr[i] << ' ';
    }
    cout << endl;

}



int main() {

    const int ASIZE = 10;
    Array arr(ASIZE);

    for (int j = 0; j < ASIZE; j++)
        arr[j] = j * j;

    cout << "arr: "; arr.print();

    Array arr2(arr);
    cout << "arr2: "; arr2.print();

    Array arr3(ASIZE);
    arr3 = arr;
    cout << "arr3: "; arr3.print();

    Array arr4(ASIZE+5);
    arr4 = arr;
    cout << "arr4: "; arr4.print();

    Array arr5(ASIZE-5);
    arr5 = arr;
    cout << "arr5: "; arr5.print();

    return 0;

}
