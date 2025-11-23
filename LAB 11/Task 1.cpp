#include <bits/stdc++.h>
#include <string>
using namespace std;
const int TABLE_SIZE = 10;

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
    int hashFunction(const string& s) {
        int sum = 0;
        for(char c : s) sum += c;
        return sum % TABLE_SIZE;
    }
public:
    HashTable() {
        for(int i = 0; i < TABLE_SIZE; i++) table[i] = nullptr;
    }
    void insert(const string& key, const string& val) {
        int index = hashFunction(key);
        Node* current = table[index];
        while(current != nullptr) {
            if(current->key == key) {
                current->value = val;
                return;
            }
            current = current->next;
        }
        Node* newNode = new Node(key, val);
        newNode->next = table[index];
        table[index] = newNode;
    }
    string search(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while(current != nullptr) {
            if(current->key == key) return current->value;
            current = current->next;
        }
        return "NOT FOUND";
    }
    void remove(const string& key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;
        while(temp != nullptr && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == nullptr) {
            cout << "Key " << key << " not found\n";
            return;
        }
        if(prev == nullptr) table[index] = temp->next;
        else prev->next = temp->next;
        delete temp;
        cout << "Key " << key << " deleted\n";
    }
    void display() {
        for(int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << " : ";
            Node* current = table[i];
            if(!current) cout << "EMPTY";
            while(current != nullptr) {
                cout << " -> [Key: " << current->key
                     << ", Value: " << current->value << "]";
                current = current->next;
            }
            cout << endl;
        }
    }
    ~HashTable() {
        for(int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            while(current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable myhash;
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");
    cout << myhash.search("A") << endl;
    cout << myhash.search("C") << endl;
    myhash.display();
}
