#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head=tail=NULL;
    }

    void displayll(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void pushback(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        
        tail->next=newNode;
        tail=newNode;   
    }

    void rotate(int num){
        Node*temp=head;
        Node*newhead=NULL;
        for(int i=0; i<num-1; i++){
            temp=temp->next;
        }
        newhead=temp->next;
        tail->next=head;
        tail=head;
        head=newhead;
        temp->next=NULL;
    }
};

int main() {
    
    List ll;

    ll.pushback(1);
    ll.pushback(2);
    ll.pushback(3);
    ll.pushback(4);

    ll.rotate(2);

    ll.displayll();

    return 0;
    
}
