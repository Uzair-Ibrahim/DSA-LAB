#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int Value;
    Node* Next;
    Node(int val) {
        Value = val;
        Next = NULL;
    }
};
class MaxHeap {
    Node* Head;
   int Size;
    Node* getNode(int index) {
        Node* temp = Head;
        for (int i = 0; i < index && temp; i++)
            temp = temp->Next;
        return temp;
    }
    int parent(int i) { 
        return (i - 1) / 2; 
    }
    int left(int i) { 
        return 2 * i + 1; 
    }
    int right(int i) { 
        return 2 * i + 2; 
    }
    void swapNodes(Node* a, Node* b) {
        int t = a->Value;
        a->Value = b->Value;
        b->Value = t;
    }
    void heapify_up(int index) {
        while (index != 0) {
            int p = parent(index);
            Node* current = getNode(index);
            Node* par = getNode(p);
            if (par->Value < current->Value) {
                swapNodes(current, par);
                index = p;
            } else break;
        }
    }
    void heapify_down(int index) {
        while (true) {
            int l = left(index);
            int r = right(index);
            int max_index = index;
            Node* current = getNode(index);
            Node* leftNode = getNode(l);
            Node* rightNode = getNode(r);
            if (l < Size && leftNode->Value > current->Value) max_index = l;
            if (r < Size && rightNode->Value > getNode(max_index)->Value) max_index = r;

            if (max_index != index) {
                swapNodes(current, getNode(max_index));
                index = max_index;
            } else break;
        }
    }
public:
    MaxHeap() {
        Head = NULL;
        Size = 0;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!Head) Head = newNode;
        else {
            Node* temp = Head;
            while (temp->Next) temp = temp->Next;
            temp->Next = newNode;
        }
        Size++;
        heapify_up(Size - 1);
    }
    void update_key(int index, int new_val) {
        if (index >= Size) {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node* node = getNode(index);
        int old_val = node->Value;
        node->Value = new_val;
        if (new_val > old_val) heapify_up(index);
        else heapify_down(index);
    }
    void delete_element(int index) {
        if (index >= Size) {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node* lastNode = getNode(Size - 1);
        Node* delNode = getNode(index);
        swapNodes(delNode, lastNode);
        if (Size == 1) {
            delete Head;
            Head = NULL;
        } else {
            Node* secondLast = getNode(Size - 2);
            delete secondLast->Next;
            secondLast->Next = NULL;
        }
        Size--;
        if (index < Size) heapify_down(index);
    }
    void printHeap() {
        Node* temp = Head;
        while (temp) {
            cout << temp->Value << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    heap.insert(8);
    heap.insert(7);
    heap.insert(6);
    heap.insert(5);
    heap.insert(4);
    cout << "Initial Max Heap: ";
    heap.printHeap();
    cout << "\nUpdate index 2 to 10" << endl;
    heap.update_key(2, 10);
    cout << "Heap after update: ";
    heap.printHeap();
    cout << "\nDelete element at index 1" << endl;
    heap.delete_element(1);
    cout << "Heap after delete: ";
    heap.printHeap();
}
