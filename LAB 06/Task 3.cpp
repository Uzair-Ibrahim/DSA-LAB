#include <iostream>
using namespace std;

bool isSafe(int maze[4][4], int sol[4][4], int x, int y){
    return (x>=0 && x<4 && y>=0 && y<4 && maze[x][y]==1 && sol[x][y]==0);
}

bool solveMazeUtil(int maze[4][4], int sol[4][4], int x, int y, string path[], int &idx){
    if(x==0 && y==0 && maze[x][y]==1){
        sol[x][y]=1;
        return true;
    }
    if(isSafe(maze, sol, x, y)){
        sol[x][y]=1;
        if(solveMazeUtil(maze, sol, x-1, y, path, idx)){
            path[idx++]="up";
            return true;
        }
        if(solveMazeUtil(maze, sol, x+1, y, path, idx)){
            path[idx++]="down";
            return true;
        }
        if(solveMazeUtil(maze, sol, x, y+1, path, idx)){
            path[idx++]="right";
            return true;
        }
        if(solveMazeUtil(maze, sol, x, y-1, path, idx)){
            path[idx++]="left";
            return true;
        }
        sol[x][y]=0;
        return false;
    }
    return false;
}

int main(){
    int maze[4][4]={{1,1,1,1},{0,0,0,1},{1,1,0,1},{1,1,1,1}};
    int sol[4][4]={0};
    string path[100];
    int idx=0;
    if(solveMazeUtil(maze, sol, 3, 0, path, idx)){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) cout<<sol[i][j]<<" ";
            cout<<endl;
        }
        cout<<"Path from (3,0) to (0,0): ";
        for(int i=idx-1;i>=0;i--){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }else cout<<"No path"<<endl;
    return 0;
}
