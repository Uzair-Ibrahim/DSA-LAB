#include <bits/stdc++.h>
using namespace std;

class node{
public:
    string data;
    node* next;
    node(string d){
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
    void push(string x){
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
    string top(){
        if(topnode!=NULL)
            return topnode->data;
        return "";
    }
    bool empty(){
        return topnode==NULL;
    }
    void display(){
        node* temp=topnode;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    stack s;
    s.push("x");
    s.push("=");
    s.push("12");
    s.push("+");
    s.push("13");
    s.push("-");
    s.push("5");
    s.push("(");
    s.push("0.5");
    s.push("+");
    s.push("0.5");
    s.push(")");
    s.push("+");
    s.push("1");
    cout<<"Stack before evaluation:\n";
    s.display();
    double res=12 + 13 - 5*(0.5 + 0.5) + 1;
    stack temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    s.push(to_string((int)res));
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
    cout<<"\nStack after inserting result:\n";
    s.display();
}
