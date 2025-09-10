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

    void rotateEvens(){
        if(head==NULL) return;
        Node* evenHead=NULL;
        Node* evenTail=NULL;
        Node* oddHead=NULL;
        Node* oddTail=NULL;
        Node* cur=head;
        while(cur!=NULL){
            Node* next=cur->next;
            cur->next=NULL;
            if(cur->data % 2==0){
                if(evenHead==NULL){
                    evenHead=evenTail=cur;
                }
                else{
                    evenTail->next=cur;
                    evenTail=cur;
                }
            } 
            else{
                if(oddHead==NULL){
                    oddHead=oddTail=cur;
                } 
                else{
                    oddTail->next=cur;
                    oddTail=cur;
                }
            }
            cur=next;
        }
        if(evenHead==NULL) head=oddHead;
        else{
            head=evenHead;
            evenTail->next=oddHead;
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
    List ll;
    ll.push_back(9);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(3);
    cout<<"list before rotation:"<<endl;
    ll.printll();
    
    ll.rotateEvens();
    cout<<"list after rotation:"<<endl;
    ll.printll();
    return 0;
}
