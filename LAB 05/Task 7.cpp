#include <bits/stdc++.h>
using namespace std;
int n=4;
int sol[4][4];

bool safe(int r,int c){
    for(int i=0;i<r;i++)
        if(sol[i][c]) return 0;
    for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--)
        if(sol[i][j]) return 0;
    for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++)
        if(sol[i][j]) return 0;
    return 1;
}

bool go(int r){
    if(r==n) return 1;
    for(int c=0;c<n;c++){
        if(safe(r,c)){
            sol[r][c]=1;
            if(go(r+1)) return 1;
            sol[r][c]=0;
        }
    }
    return 0;
}

int main(){
    memset(sol,0,sizeof(sol));
    if(go(0)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<sol[i][j]<<" ";
            cout<<"\n";
        }
    } else cout<<"no sol\n";
}
