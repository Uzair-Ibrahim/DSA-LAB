#include <bits/stdc++.h>
using namespace std;
int func(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])return 1;
        }
    }
    return 0;
}
int main(){
    int arr[]={1,2,3,4,5,2},n=6;
    if(func(arr,n)){ 
      cout<<"duplicate";
    }
    else{
      cout<<"no duplicate";
    }
}
