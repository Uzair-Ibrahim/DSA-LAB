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

    void pushBack(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }

    Node* reverse(Node* head){
        Node* pre=NULL;
        Node* cur=head;
        Node* next=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    bool isPalindrome() {
        Node* slow=head;
        Node* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* start=head;
        Node* mid=reverse(slow);

        while(mid != NULL) {
            if(start->data != mid->data) {
                return false;
            }
            start = start->next;
            mid = mid->next;
        }
        return true;
    }

    void display(){
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
    ll.pushBack(1);
    ll.pushBack(3);
    ll.pushBack(1);
    ll.pushBack(33);
    
    ll.display();

    bool isPal=ll.isPalindrome();
    if(isPal){
        cout<<"this is a palindrome!"<<endl;
    }
    else{
        cout<<"this is not a palindrome!"<<endl;
    }
    return 0;
}