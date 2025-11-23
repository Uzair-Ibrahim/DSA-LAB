#include <bits/stdc++.h>
using namespace std;
const int TABLE_SIZE = 100;

class Node {
public:
    string key;
    string value;
    Node* next;
    Node(const string& k, const string& v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
private:
    Node* table[TABLE_SIZE];
    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key)
            sum += int(c);
        return sum % TABLE_SIZE;
    }
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }
    void Add_Record(const string& key, const string& value) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }
    void Word_Search(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                cout << "search key " << key << ": " << current->value << endl;
                return;
            }
            current = current->next;
        }
        cout << "Error: " << key << " not found!" << endl;
    }
    void Delete_Record(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Error: " << key << " not found!" << endl;
            return;
        }
        if (prev == nullptr)
            table[index] = current->next;
        else
            prev->next = current->next;
        delete current;
        cout << "key " << key << " deleted successfully !" << endl;
    }
    void Print_Dictionary() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            if (current) {
                cout << "index " << i << ": ";
                while (current != nullptr) {
                    cout << "(" << current->key << ", " << current->value << ")";
                    if (current->next != nullptr) cout << " -> ";
                    current = current->next;
                }
                cout << endl;
            }
        }
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
    HashTable dict;
    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "ENG");
    dict.Word_Search("AB");
    dict.Delete_Record("EF");
    dict.Print_Dictionary();
    return 0;
}
