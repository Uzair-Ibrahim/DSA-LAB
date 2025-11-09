#include <iostream>
using namespace std;

class stack{
public:
    char arr[100];
    int topindex;
    stack(){
        topindex=-1;
    }
    void push(char x){
        if(topindex<99){
            topindex++;
            arr[topindex]=x;
        }
    }
    void pop(){
        if(topindex>=0)
            topindex--;
    }
    char top(){
        if(topindex>=0)
            return arr[topindex];
        return '\0';
    }
    bool empty(){
        return topindex==-1;
    }
};

int main(){
    string word="BORROWROB";
    stack s;
    for(int i=0;i<word.length();i++)
        s.push(word[i]);

    bool palindrome=true;
    for(int i=0;i<word.length();i++){
        if(word[i]!=s.top()){
            palindrome=false;
            break;
        }
        s.pop();
    }

    cout<<"Word: "<<word<<endl;
    if(palindrome)
        cout<<"It is a palindrome"<<endl;
    else
        cout<<"It is not a palindrome"<<endl;
}
