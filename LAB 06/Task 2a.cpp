#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d):data(d),next(nullptr),prev(nullptr){}
};
class doubly{
public:
    Node* head;
    Node* tail;
    doubly():head(nullptr),tail(nullptr){}
    void append(int d){
        Node* n=new Node(d);
        if(!head) head=tail=n;
        else{
            tail->next=n;
            n->prev=tail;
            tail=n;
        }
    }
    void bubsort(){
        if(!head) return;
        bool swapped;
        do{
            swapped=false;
            Node* curr=head;
            while(curr->next){
                if(curr->data > curr->next->data){
                    int temp=curr->data;
                    curr->data=curr->next->data;
                    curr->next->data=temp;
                    swapped=true;
                }
                curr=curr->next;
            }
        }while(swapped);
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

int main(){
    doubly dl;
    dl.append(3);
    dl.append(1);
    dl.append(2);
    dl.bubsort();
    dl.print();
    return 0;
}
