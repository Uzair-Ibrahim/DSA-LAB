#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void pop_front(Node*& head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void pop_back(Node*& head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
void pop_pos(Node*& head, int position) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (position == 0) {
        pop_front(head);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range." << endl;
        return;
    }
    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}
void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout << "Original List: ";
    display(head);
    pop_front(head);
    cout << "After Deleting from Front: ";
    display(head);
    pop_back(head);
    cout << "After Deleting from Last: ";
    display(head);
    pop_pos(head, 1);
    cout << "After Deleting at Position 1: ";
    display(head);
    return 0;
}
