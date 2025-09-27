#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }

    void add(int val) {
        Node* n = new Node(val);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }

    int lenTail(Node* h, int c = 0) {
        if (!h) return c;
        return lenTail(h->next, c + 1);
    }

    int length() {
        return lenTail(head, 0);
    }
};

int main() {
    List l;
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);
    cout << l.length() << endl;
}
