#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[9]={20,12,15,2,10,1,13,9,5},n=9;
    for(int i=1;i<n;i++){
        int k=arr[i],j=i-1;
        while(j>=0&&arr[j]>k){
          arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
    int brr[9],m=n/2; 
    brr[m]=arr[n-1]; 
    int x=0;
    for(int i=0;i<n;i++){
      if(i==m) continue; 
      brr[i]=arr[x++];
    }
    for(int i=0;i<n;i++) cout<<brr[i]<<" ";
}
