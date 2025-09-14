#include <bits/stdc++.h>
using namespace std;
int bin_search(int arr[],int n,int x){
    int start=0,end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]<x) start=mid+1;
        else end=mid-1;
    }
    return -1;
}
int main(){
    int arr[]={12,45,23,67,34,89,50,77},n=8;
    sort(arr,arr+n);
    int x=45;
    int id=bin_search(arr,n,x);
    if(id==-1){
        arr[n++]=x;
        sort(arr,arr+n);
        id=bin_search(arr,n,x);
    }
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<"\n"<<id;
}

