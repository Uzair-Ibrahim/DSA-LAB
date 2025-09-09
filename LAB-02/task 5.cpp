#include <bits/stdc++.h>
using namespace std;
int main() {
    int depts;
    cout<<"enter number of departments: ";
    cin>>depts;
    int**dept=new int*[depts];
    int courses[4];
    for(int i=0; i<depts; i++){
        cout<<"enter number of courses for department# "<<i+1<<endl;
        cin>>courses[i];
        dept[i]=new int[courses[i]];
    } 
    for(int i=0; i<depts; i++){
        cout<<"enter GPA of courses for department# "<<i+1<<endl;
        for(int j=0; j<courses[i]; j++){
            cin>>dept[i][j];
        }
    }
    for(int i=0; i<depts; i++){
        cout<<"department# "<<i+1<<" courses GPA"<<endl;
        for(int j=0; j<courses[i]; j++){
            cout<<dept[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<depts; i++){
        delete [] dept;
    }
    delete [] dept;
    return 0;
}
