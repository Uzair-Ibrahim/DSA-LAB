#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    List() {
        head = nullptr;
    }
    void pushFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
private:
    Node* getTail(Node* cur) {
        while (cur != nullptr && cur->next != nullptr)
            cur = cur->next;
        return cur;
    }
    Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node* prev = nullptr;
        Node* cur = head;
        Node* tail = pivot;
        while (cur != pivot) {
            if (cur->data < pivot->data) {
                if ((*newHead) == nullptr)
                    *newHead = cur;
                prev = cur;
                cur = cur->next;
            } else {
                if (prev)
                    prev->next = cur->next;
                Node* tmp = cur->next;
                cur->next = nullptr;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }
        if ((*newHead) == nullptr)
            *newHead = pivot;
        *newEnd = tail;
        return pivot;
    }
    Node* quickSortRecur(Node* head, Node* end) {
        if (!head || head == end)
            return head;
        Node* newHead = nullptr;
        Node* newEnd = nullptr;
        Node* pivot = partition(head, end, &newHead, &newEnd);
        if (newHead != pivot) {
            Node* tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = nullptr;
            newHead = quickSortRecur(newHead, tmp);
            tmp = getTail(newHead);
            tmp->next = pivot;
        }
        pivot->next = quickSortRecur(pivot->next, newEnd);
        return newHead;
    }
public:
    void quickSort() {
        head = quickSortRecur(head, getTail(head));
    }
};

int main() {
    List list;
    list.pushFront(3);
    list.pushFront(5);
    list.pushFront(1);
    list.pushFront(9);
    list.pushFront(8);
    list.pushFront(7);
    list.pushFront(10);
    cout << "Original list: ";
    list.printList();
    list.quickSort();
    cout << "Sorted list: ";
    list.printList();
    return 0;
}
