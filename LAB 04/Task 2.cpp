#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[9]={20,12,15,2,10,1,13,9,5},n=9;
    for(int i=1;i<n;i++){
        int k=a[i],j=i-1;
        while(j>=0&&a[j]>k){
          a[j+1]=a[j];j--;
        }
        a[j+1]=k;
    }
    int b[9],m=n/2; 
    b[m]=a[n-1]; 
    int x=0;
    for(int i=0;i<n;i++){
      if(i==m) continue; 
      b[i]=a[x++];
    }
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
}
