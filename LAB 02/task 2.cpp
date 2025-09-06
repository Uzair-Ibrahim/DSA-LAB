#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){data=val;next=NULL;}
};
class LinkedList{
private:
    Node* head;
    Node* tail;
public:
    LinkedList(){head=NULL;tail=NULL;}
    void insertEnd(int val){
        Node* newNode=new Node(val);
        if(head==NULL){head=tail=newNode;return;}
        tail->next=newNode;
        tail=newNode;
    }
    void rotate(int k){
        if(head==NULL||k==0) return;
        Node* temp=head;
        int count=1;
        while(count<k && temp!=NULL){temp=temp->next;count++;}
        if(temp==NULL) return;
        Node* newHead=temp->next;
        if(newHead==NULL) return;
        tail->next=head;
        head=newHead;
        tail=temp;
        tail->next=NULL;
    }
    void printList(){
        Node* temp=head;
        while(temp!=NULL){cout<<temp->data<<" ";temp=temp->next;}
        cout<<endl;
    }
};
int main(){
    LinkedList list;
    int k;
    int arr[]={5,3,1,8,6,4,2};
    for(int i=0;i<7;i++) {
        list.insertEnd(arr[i]);
    }
    cout<<"Given list: ";
    list.printList();
    cout<<"Enter the number: ";
    cin>>k;
    list.rotate(k);
    cout<<"After rotation: ";
    list.printList();
    return 0;
}