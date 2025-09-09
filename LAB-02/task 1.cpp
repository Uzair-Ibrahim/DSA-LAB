#include <bits/stdc++.h>
using namespace std;

class matrix {
    int** arr;
    int rows;
    int cols;
    public:
    matrix(int r, int c) {
        rows = r;
        cols = c;
        arr = new int*[rows];
        for(int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }
    }
    void setval() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cin >> arr[i][j];
            }
        }
    }
    int getr() {
        return rows;
    }
    int getc() {
        return cols;
    }
    int** getval() {
        return arr;
    }
    void resize(int nrows, int ncols) {
        if(rows == nrows && cols == ncols) {
            return;
        }
        int** newarr = new int*[nrows];
        for(int i = 0; i < nrows; i++) {
            newarr[i] = new int[ncols]();
        }
        int minRows = min(rows, nrows);
        int minCols = min(cols, ncols);        
        for(int i = 0; i < minRows; i++) {
            for(int j = 0; j < minCols; j++) {
                newarr[i][j] = arr[i][j];
            }
        }
        for(int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;    
        arr = newarr;
        rows = nrows;
        cols = ncols;
    }
    void transpose(){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(i>j){
                    int temp=arr[i][j];
                    arr[i][j]=arr[j][i];
                    arr[j][i]=temp;
                }
            }
        }
    }
    void print() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    void add2() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(i%2!=0 || j%2!=0){
                    arr[i][j]+=2;
                }
            }
        }
    }
    ~matrix() {
        for(int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main() {
    int rows, cols;
    cout << "enter rows: ";
    cin >> rows;
    cout << "enter cols: ";
    cin >> cols;
    matrix m(rows, cols);
    cout << "Enter matrix elements:" << endl;
    m.setval();
    cout << "Original matrix:" << endl;
    m.print();
    int nr, nc;
    cout << "enter new rows: ";
    cin >> nr;
    cout << "enter new cols: ";
    cin >> nc;
    m.resize(nr, nc);
    if(nr>rows||nc>cols) {
        cout << "Enter additional elements for the expanded matrix:" << endl;
        int** arr = m.getval();
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(i >= rows || j >= cols) {
                    cout << "Element [" << i << "][" << j << "]: ";
                    cin >> arr[i][j];
                }
            }
        }
    }
    cout << "resized matrix:" << endl;
    m.print();
    m.transpose();
    cout<<"transposed matrix!"<<endl;
    m.print();
    m.add2();
    cout<<"after add 2 at odd indices matrix!"<<endl;
    m.print();
    return 0;
}
