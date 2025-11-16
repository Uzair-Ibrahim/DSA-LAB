#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    int heap[100];
    int size;
    int parent(int i) { 
        return (i - 1) / 2; 
    }
    int left(int i) { 
        return 2 * i + 1; 
    }
    int right(int i) { 
        return 2 * i + 2; 
    }
    void heapify_up(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void heapify_down(int i) {
        int max_index = i;
        while (true) {
            int l = left(i);
            int r = right(i);
            if (l < size && heap[l] > heap[max_index]) max_index = l;
            if (r < size && heap[r] > heap[max_index]) max_index = r;
            if (max_index != i) {
                swap(heap[i], heap[max_index]);
                i = max_index;
            } else break;
        }
    }
public:
    MaxHeap() { 
        size = 0; 
    }
    void insert(int val) {
        heap[size] = val;
        size++;
        heapify_up(size - 1);
    }
    void update_key(int index, int new_val) {
        if (index >= size) {
            cout << "Index out of bounds" << endl;
            return;
        }
        int old_val = heap[index];
        heap[index] = new_val;
        if (new_val > old_val) heapify_up(index);
        else heapify_down(index);
    }
    void delete_element(int index) {
        if (index >= size) {
            cout << "Index out of bounds" << endl;
            return;
        }
        heap[index] = heap[size - 1];
        size--;
        heapify_down(index);
    }
    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
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
