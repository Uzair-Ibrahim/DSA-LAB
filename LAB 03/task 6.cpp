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

    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }

    void deleteVal(int val){
        Node*temp=head;
        Node*prev=NULL;
        bool found=false;
        while(temp!=NULL){
            if(temp->data==val){
                if(prev==NULL) head=temp->next;
                else prev->next=temp->next;
                delete temp; 
                found=true;
                return;
            }
            else{
                found=false;
            }
            prev=temp;
            temp=temp->next;
        }
        if(found)cout<<val<<" from the list has been deleted!"<<endl;
        else cout<<val<<" is not found in list!!"<<endl;
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
    List ll;
    ll.push_back(9);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(3);
    cout<<"list before deletion:"<<endl;
    ll.printll();
    
    int val;
    cout<<"enter value you want to delete: ";
    cin>>val;

    ll.deleteVal(val);
    ll.printll();
    return 0;
}
