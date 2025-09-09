#include <bits/stdc++.h>
using namespace std;
int main() {
    int rows;
    cout<<"enter number of rows: ";
    cin>>rows;
    string**names=new string*[rows];
    int *seats=new int[rows];
    int cols;
    for(int i=0; i<rows; i++){
        cout<<"enter number of seats in row# "<<i+1<<endl;
        cin>>cols;
        names[i]=new string[cols];
        seats[i]=cols;
    } 
    for(int i=0; i<rows; i++){
        cout<<"enter names of persons in row# "<<i+1<<endl;
        for(int j=0; j<seats[i]; j++){
            cout<<"enter the name of person: ";
            cin>>names[i][j];
        }
    }
    for(int i=0; i<rows; i++){
        cout<<"row# "<<i+1<<" seats:"<<endl;
        for(int j=0; j<seats[i]; j++){
            cout<<names[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<rows; i++){
        delete [] names;
    }
    delete [] names;
    delete [] seats;
    return 0;
}