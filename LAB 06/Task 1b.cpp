#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class List {
public:
    Node* head;

    List() {
        head = nullptr;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    Node* reverseDLL(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }
        Node* newHead = reverseDLL(node->next);
        node->next->next = node;
        node->prev = node->next;
        node->next = nullptr;
        return newHead;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    List list;

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);
    list.insertEnd(5);

    cout << "Original List: ";
    list.printList();

    list.head = list.reverseDLL(list.head);

    cout << "Reversed List: ";
    list.printList();

    return 0;
}
