#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2022,2023,2024,2022,2023,2024},n=6;
    int c1=0,c2=0,c3=0;
    int k=0;
    for(int i=0;i<n;i++){
        if(arr[i]==2022) c1++;
        else if(arr[i]==2023) c2++;
        else c3++;
    }
    while(c1--) arr[k++]=2022;
    while(c2--) arr[k++]=2023;
    while(c3--) arr[k++]=2024;
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}
