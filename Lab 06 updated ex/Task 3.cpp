#include <iostream>
using namespace std;

class node{
public:
    char data;
    node* next;
    node(char d){
        data=d;
        next=NULL;
    }
};

class stack{
public:
    node* topnode;
    stack(){
        topnode=NULL;
    }
    void push(char x){
        node* n=new node(x);
        n->next=topnode;
        topnode=n;
    }
    void pop(){
        if(topnode!=NULL){
            node* temp=topnode;
            topnode=topnode->next;
            delete temp;
        }
    }
    char top(){
        if(topnode!=NULL)
            return topnode->data;
        return '\0';
    }
    bool empty(){
        return topnode==NULL;
    }
};

int prec(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

int main(){
    string infix="a+b*(c^d-e)^(f+g*h)-i";
    string postfix="";
    stack s;
    for(int i=0;i<infix.length();i++){
        char c=infix[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
            postfix+=c;
        else if(c=='(')
            s.push(c);
        else if(c==')'){
            while(!s.empty() && s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        }
        else{
            while(!s.empty() && prec(s.top())>=prec(c)){
                postfix+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    cout<<"Postfix: "<<postfix<<endl;
}
