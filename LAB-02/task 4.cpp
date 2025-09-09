#include <bits/stdc++.h>
using namespace std;
int main() {
    bool arr[5][5]={
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,1,0,0,0},
        {1,0,0,0,1},
        {1,1,0,1,0}
    };
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(arr[i][j]==true){
                cout<<"row "<<i+1<<" and "<<j+1<<" column are friends."<<endl;
            }else{
                cout<<"row "<<i+1<<" and "<<j+1<<" column are not friends."<<endl;
            }
        }
    }
    return 0;
}
