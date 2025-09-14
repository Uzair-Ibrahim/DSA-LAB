#include <bits/stdc++.h>
using namespace std;

int lsearch(string arr[],int n,string x,int &st){
    for(int i=0; i<n; i++){
      st++;
      if(arr[i]==x) return i;
    }
    return -1;
}

int bsearch(string arr[],int n,string x,int &st){
    int start=0,end=n-1;
    while(start<=end){
        st++;
        int mid=(start+end)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]<x) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

int main(){
    string arr[]={"Ahmed","Ali","Basit","Karim","Rizwan","Sarwar","Tariq","Taufiq","Yasin","Zulfiqar"};
    int n=10;
    string qrr[]={"Aftab","Rizwan","Tariq"};
    for(int i=0;i<3;i++){
        int st1=0,st2=0;
        int p1=lsearch(arr,n,qrr[i],st1);
        int p2=bsearch(arr,n,qrr[i],st2);
        cout<<qrr[i]<<":\n";
        cout<<"linear idx="<<p1<<" steps="<<st1<<"\n";
        cout<<"binary idx="<<p2<<" steps="<<st2<<"\n\n";
    }
}
