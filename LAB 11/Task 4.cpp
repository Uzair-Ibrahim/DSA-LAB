#include <bits/stdc++.h>
using namespace std;
const int TABLE_SIZE = 100;

class Node {
public:
    int a, b;
    Node* next;
    Node(int x, int y) {
        a = x;
        b = y;
        next = nullptr;
    }
};

class HashTable {
private:
    Node* table[TABLE_SIZE];
    int hashFunction(int sum) {
        return sum % TABLE_SIZE;
    }
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }
    bool insert(int x, int y, int sum, int &foundA, int &foundB, int &foundC, int &foundD) {
        int index = hashFunction(sum);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->a != x && current->a != y && current->b != x && current->b != y) {
                foundA = current->a;
                foundB = current->b;
                foundC = x;
                foundD = y;
                return true;
            }
            current = current->next;
        }
        Node* newNode = new Node(x, y);
        newNode->next = table[index];
        table[index] = newNode;
        return false;
    }
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int n1 = 7;
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int n2 = 6;
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    int n3 = 7;
    int* tests[] = {arr1, arr2, arr3};
    int sizes[] = {n1, n2, n3};
    for (int t = 0; t < 3; t++) {
        int* arr = tests[t];
        int n = sizes[t];
        HashTable ht;
        bool found = false;
        int a, b, c, d;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];
                if (ht.insert(arr[i], arr[j], sum, a, b, c, d)) {
                    cout << "(" << a << ", " << b << ") and (" << c << ", " << d << ")" << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) cout << "No pairs found" << endl;
    }
    return 0;
}
