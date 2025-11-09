#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int d):data(d),next(NULL){}
};
class List{
public:
    Node* head;
    Node* tail;
    List():head(NULL),tail(NULL){}
    void append(int d){
        Node* n=new Node(d);
        if(!head) head=tail=n;
        else{
            tail->next=n;
            tail=n;
        }
    }
    void print(){
        Node* curr=head;
        while(curr){
            cout<<curr->data;
            if(curr->next) cout<<"->";
            curr=curr->next;
        }
        cout<<endl;
    }
};
void merge(List& l1, List& l2){
    Node* curr1=l1.head;
    Node* curr2=l2.head;
    Node* next1;
    Node* next2;
    while(curr1 && curr2){
        next1=curr1->next;
        next2=curr2->next;
        curr1->next=curr2;
        curr2->next=next1;
        curr1=next1;
        curr2=next2;
    }
    l2.head=curr2;
}
int main(){
    List l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    List l2;
    l2.append(4);
    l2.append(5);
    l2.append(6);
    l2.append(7);
    l2.append(8);
    merge(l1,l2);
    l1.print();
    l2.print();
    return 0;
}
