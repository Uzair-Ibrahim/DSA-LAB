
/*
Algorithm to concatenate two doubly linked lists L and M:
1. Check if L is empty → if yes, return M's head as new head and M's tail as new tail.
2. Check if M is empty → if yes, return L's head as new head and L's tail as new tail.
3. Connect L's tail to M's head: L.tail->next = M.head
4. Connect M's head back to L's tail: M.head->prev = L.tail
5. Set new tail = M.tail
6. Return new head = L.head
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList{
public:
    Node* head;
    Node* tail;
    DoublyList(){ head = tail = NULL; }

    void pushBack(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void concatenate(DoublyList &M){
        if(head == NULL){
            head = M.head;
            tail = M.tail;
            return;
        }
        if(M.head == NULL) return;

        tail->next = M.head;
        M.head->prev = tail;
        tail = M.tail;
    }
};

int main(){
    DoublyList L, M;

    L.pushBack(1);
    L.pushBack(2);
    L.pushBack(3);

    M.pushBack(4);
    M.pushBack(5);
    M.pushBack(6);

    L.concatenate(M);

    L.display();

    return 0;
}
