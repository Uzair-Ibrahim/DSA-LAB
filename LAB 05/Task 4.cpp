#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { 
      data = val; next = NULL; 
    }
};

class List {
    Node* head;
public:
    List() { 
      head = NULL; 
    }
    void add(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }
    bool srec(Node* h, int x) {
        if (!h) return 0;
        bool f = srec(h->next, x);
        if (h->data == x) return 1;
        return f;
    }
    bool srch(int x) { 
      return srec(head, x); 
    }
};

int main() {
    List l;
    l.add(10);
    l.add(20);
    l.add(30);
    cout << (l.srch(20) ? "yes\n" : "no\n");
    cout << (l.srch(50) ? "yes\n" : "no\n");
}
