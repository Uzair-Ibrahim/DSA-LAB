#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[10];
    for(int i=0;i<10;i++) cin>>arr[i];
    for(int i=0;i<10;i++){
        int m=i;
        for(int j=i+1;j<10;j++){
            if(arr[j]<arr[m]) m=j;
        }
        swap(arr[i],arr[m]);
    }
    for(int i=0; i<4; i++) cout<<arr[i]<<" ";
}
