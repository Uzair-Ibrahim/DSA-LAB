#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){data=val;next=NULL;}
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    void insertEnd(int val){
        Node* newNode=new Node(val);
        if(head==NULL){head=newNode;return;}
        Node* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newNode;
    }
    void insertFront(int val){
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
    }
    void insertAt(int val,int pos){
        if(pos==1){insertFront(val);return;}
        Node* temp=head;
        for(int i=1;i<pos-1&&temp!=NULL;i++) temp=temp->next;
        if(temp==NULL) return;
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void deleteVal(int key){
        Node* temp=head;Node* prev=NULL;
        while(temp!=NULL){
            if(temp->data==key){
                if(prev==NULL) head=temp->next;
                else prev->next=temp->next;
                delete temp;return;
            }
            prev=temp;temp=temp->next;
        }
    }
    void printList(){
        Node* temp=head;
        while(temp!=NULL){cout<<temp->data<<" ";temp=temp->next;}
        cout<<endl;
    }
};

int main(){

    int arr[5]={3,1,2,5,8};

    cout<<"Array: ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    LinkedList list;
    for(int i=0;i<5;i++) {
        list.insertEnd(arr[i]);
    }
    cout<<"Initial Linked List: ";
    list.printList();
    list.insertEnd(9);
    list.insertAt(11,3);
    list.insertFront(4);
    cout<<"After Insertions: ";
    list.printList();
    list.deleteVal(1);
    list.deleteVal(2);
    list.deleteVal(5);
    cout<<"After Deletions: ";
    list.printList();
    return 0;
}
