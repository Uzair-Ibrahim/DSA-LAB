#include <iostream>
using namespace std; 
void push_back(char *arr, char val, int up){
    arr[up] = val;
}
char pop_back(char *arr, int up){ 
    return arr[up]; 
}
int main(){
    string a="BORROWROB"; 
    int n=a.size();
    char *right=new char[n]; 
    char *left=new char[n]; 
    int up = 0;  
    while(up<n){
        push_back(right,a[up],up);
        push_back(left,a[n-up-1],up); 
        up++; 
    }
    bool isDif=true;
    while(up>0 && isDif){
        if(pop_back(right, up)!=pop_back(left, up)) isDif = false; 
        up--; 
    }
    if(isDif) cout<<"Pwordlindrome!!!!"<<endl; 
    else cout<<"Not pwordlindrome!!"; 
}
