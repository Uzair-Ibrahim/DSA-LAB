#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* next;
    int data;
    Node(int val){
        data = val;
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

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }

    void intsert_at(int val, int pos){
        Node* newNode=new Node(val);
        Node* temp=head;
        if(pos<0){
            cout<<"invalid position!"<<endl;
            return;
        }
        if(pos==1){
            push_front(val);
            return;
        }
        for(int i=0; i<pos-1; i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void deleteVal(int val){
        Node*temp=head;
        Node*prev=NULL;
        while(temp!=NULL){
            if(temp->data==val){
                if(prev==NULL) head=temp->next;
                else prev->next=temp->next;
                delete temp; 
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    void printll(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;

    }
};

int main() {
    int* arr=new int[5]{3,1,2,5,8};

    List ll;
    for(int i=0; i<5; i++){
        ll.push_back(arr[i]);
    }
    ll.push_back(9);
    ll.intsert_at(11,3);
    ll.push_front(4);
    ll.deleteVal(1);
    ll.deleteVal(2);
    ll.deleteVal(5);
    ll.printll();
    delete []arr;
    return 0;
}
