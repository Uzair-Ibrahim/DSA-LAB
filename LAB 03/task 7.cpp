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

class CircularList{
    Node* head;
    public:
    CircularList(){ head = NULL; }

    void display(){
        if(head == NULL){
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do{
            cout << temp->data << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(head)\n";
    }

    void insertEnd(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertBeginning(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }

    void insertAt(int val, int pos){
        if(pos == 1){
            insertBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 1;
        while(count < pos-1 && temp->next != head){
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int val){
        if(head == NULL){
            cout << "List is empty.\n";
            return;
        }
        Node* cur = head;
        Node* prev = NULL;
        do{
            if(cur->data == val){
                if(prev == NULL){
                    Node* last = head;
                    while(last->next != head) last = last->next;
                    if(head->next == head){
                        delete head;
                        head = NULL;
                        return;
                    } else {
                        last->next = head->next;
                        Node* temp = head;
                        head = head->next;
                        delete temp;
                        return;
                    }
                } else {
                    prev->next = cur->next;
                    delete cur;
                    return;
                }
            }
            prev = cur;
            cur = cur->next;
        } while(cur != head);
        cout << "Value not found.\n";
    }
};

int main(){
    CircularList cl;
    int choice, val, pos;
    while(true){
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete a node\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value to insert at end: ";
                cin >> val;
                cl.insertEnd(val);
                break;
            case 2:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                cl.insertBeginning(val);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                cl.insertAt(val, pos);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                cl.deleteNode(val);
                break;
            case 5:
                cl.display();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
