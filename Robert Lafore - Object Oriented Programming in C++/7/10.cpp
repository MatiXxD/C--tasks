#include <iostream>
using namespace std;

class Matrix{

private:
    int arr[10][10];
    int rows;
    int cols;

public:
    Matrix() : rows(2), cols(2) {

    }

    Matrix(int i_rows, int i_cols) {
        if(i_rows > 10) rows = 10;
        else            rows = i_rows;
        if(i_cols > 10) cols = 10;
        else            cols = i_cols;
    }

    void putVal(int i, int j, int val){
        if(i < 0 || i >= rows){
            cout << "Wrong index.\n";
            return;
        }
        else if(j < 0 || j >= cols){
            cout << "Wrong index.\n";
            return;
        }
        arr[i][j] = val;
    }

    int getVal(int i, int j){
        if(i < 0 || i >= rows){
            cout << "Wrong index.\n";
            return -1;
        }
        else if(j < 0 || j >= cols){
            cout << "Wrong index.\n";
            return -1;
        }
        return arr[i][j];
    }

};

int main(){

    Matrix m1(3, 4);

    int temp = 12345;
    m1.putVal(1, 2, temp);
    temp = m1.getVal(1, 2);
    cout << "Value is " << temp << endl;

    return 0;

}
