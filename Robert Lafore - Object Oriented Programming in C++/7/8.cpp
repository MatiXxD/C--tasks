#include <iostream>
using namespace std;

class SafeArray{

private:
    static const int SIZE = 100;
    int array[SIZE];

public:
    SafeArray() {
        for(int i = 0 ; i < SIZE ; i++)
            array[i] = 0;
    }

    void putVal(int ind, int val){
        if(ind < 0 || ind >= SIZE){
            cout << "Wrong index.\n";
            return;
        }
        array[ind] = val;
    }

    void getVal(int ind){
        if(ind < 0 || ind >= SIZE){
            cout << "Wrong index.\n";
            return;
        }
        cout << "Value is " << array[ind] << endl;
    }

};




int main(){

    SafeArray sa1;
    int temp = 12345;

    sa1.putVal(7, temp);
    sa1.getVal(7);

    sa1.putVal(-1, temp);

    return 0;

}
