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

class stack{
public:
    string arr[100];
    int topindex;
    stack(){
        topindex=-1;
    }
    void push(string x){
        if(topindex<99){
            topindex++;
            arr[topindex]=x;
        }
    }
    void pop(){
        if(topindex>=0)
            topindex--;
    }
    bool empty(){
        return topindex==-1;
    }
    string top(){
        return arr[topindex];
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
