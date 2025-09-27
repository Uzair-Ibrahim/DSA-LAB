#include <bits/stdc++.h>
using namespace std;
int n = 5;
int maze[5][5] = {
    {1,1,1,1,0},
    {0,0,1,0,1},
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,1,1,0,1}
};
int sol[5][5];

bool safe(int x,int y){
    return x>=0 && y>=0 && x<n && y<n && maze[x][y]==1;
}

bool go(int x,int y){
    if(x==n-1 && y==n-1){ sol[x][y]=1; return 1; }
    if(safe(x,y)){
        sol[x][y]=1;
        if(go(x+1,y)) return 1;
        if(go(x,y+1)) return 1;
        sol[x][y]=0;
    }
    return 0;
}

int main(){
    memset(sol,0,sizeof(sol));
    if(go(0,0)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<sol[i][j]<<" ";
            cout<<"\n";
        }
    } else cout<<"no path\n";
}
