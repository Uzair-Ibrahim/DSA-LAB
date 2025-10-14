#include <iostream>
using namespace std;
bool isSafe(int board[][20],int row,int col,int N){
    for(int i=0;i<col;i++) if(board[row][i]) return false;
    for(int i=row,j=col;i>=0 && j>=0;i--,j--) if(board[i][j]) return false;
    for(int i=row,j=col;i<N && j>=0;i++,j--) if(board[i][j]) return false;
    return true;
}
bool solver(int board[][20],int col,int N){
    if(col>=N) return true;
    for(int i=0;i<N;i++){
        if(isSafe(board,i,col,N)){
            board[i][col]=1;
            if(solver(board,col+1,N)) return true;
            board[i][col]=0;
        }
    }
    return false;
}
int main(){
    int N=4;
    int board[20][20]={0};
    if(solver(board,0,N)){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cout<<(board[i][j]?"Q ":"- ");
            cout<<endl;
        }
    }else cout<<"No solution"<<endl;
    return 0;
}
