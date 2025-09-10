#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    public:
    List(){ head = NULL; }

    void pushBack(int val){
        Node* newNode = new Node(val);
        if(head == NULL){ head = newNode; return; }
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void extract(){
        if(head == NULL || head->next == NULL) return;

        Node* prev = head;
        Node* cur = head->next;
        Node* ehead = NULL;

        while(cur != NULL){
            prev->next = cur->next;
            cur->next = ehead;
            ehead = cur;

            prev = prev->next;
            if(prev != NULL) cur = prev->next;
            else break;
        }

        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = ehead;
    }
};

int main(){
    List ll;

    ll.pushBack(10);
    ll.pushBack(4);
    ll.pushBack(9);
    ll.pushBack(1);
    ll.pushBack(3);
    ll.pushBack(5);
    ll.pushBack(9);
    ll.pushBack(4);

    ll.extract();
    ll.display();

    return 0;
}
