#include <bits/stdc++.h>
using namespace std;

class node{
public:
    string url;
    node* next;
    node(string u){
        url=u;
        next=NULL;
    }
};

class linkedlist{
public:
    node* head;
    linkedlist(){
        head=NULL;
    }
    void visit(string url){
        node* n=new node(url);
        n->next=head;
        head=n;
    }
    void removefront(){
        if(head==NULL) return;
        node* temp=head;
        head=head->next;
        delete temp;
    }
    void showcurrent(){
        if(head!=NULL)
            cout<<head->url<<endl;
        else
            cout<<"none"<<endl;
    }
    void showall(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->url<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

class stacknode{
public:
    string data;
    stacknode* next;
    stacknode(string d){
        data=d;
        next=NULL;
    }
};

class stack{
public:
    stacknode* topnode;
    stack(){
        topnode=NULL;
    }
    void push(string x){
        stacknode* n=new stacknode(x);
        n->next=topnode;
        topnode=n;
    }
    void pop(){
        if(topnode!=NULL){
            stacknode* temp=topnode;
            topnode=topnode->next;
            delete temp;
        }
    }
    bool empty(){
        return topnode==NULL;
    }
    string top(){
        if(topnode!=NULL)
            return topnode->data;
        return "";
    }
};

int main(){
    linkedlist history;
    stack s;
    string sites[5] = {"Google","Facebook","Twitter","LinkedIn","Instagram"};
    for(int i=0;i<5;i++){
        history.visit(sites[i]);
        s.push(sites[i]);
    }
    cout<<"Current page: ";
    history.showcurrent();
    cout<<"All pages: ";
    history.showall();
    for(int i=0;i<2;i++){
        if(!s.empty())
            s.pop();
        history.removefront();
    }
    cout<<"After going back twice:"<<endl;
    cout<<"Current page: ";
    history.showcurrent();
    cout<<"All pages: ";
    history.showall();
}
