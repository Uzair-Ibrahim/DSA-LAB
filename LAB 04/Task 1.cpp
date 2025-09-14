#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[10];
    for(int i=0;i<10;i++) cin>>a[i];
    for(int i=0;i<10;i++){
        int m=i;
        for(int j=i+1;j<10;j++){
            if(a[j]<a[m]) m=j;
        }
        swap(a[i],a[m]);
    }
    for(int i=0;i<4;i++) cout<<a[i]<<" ";
}
