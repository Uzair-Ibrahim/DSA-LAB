#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int score;
    Student() {}
    Student(string n, int r, int s) {
        name = n;
        roll = r;
        score = s;
    }
};

class Node {
public:
    Student data;
    Node* left;
    Node* right;
    Node(Student s) {
        data = s;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;
    Node* insert(Node* node, Student s) {
        if (!node) return new Node(s);
        if (s.name < node->data.name) node->left = insert(node->left, s);
        else if (s.name > node->data.name) node->right = insert(node->right, s);
        return node;
    }
    Node* search(Node* node, string name) {
        if (!node || node->data.name == name) return node;
        if (name < node->data.name) return search(node->left, name);
        return search(node->right, name);
    }
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data.name << " " << node->data.roll << " " << node->data.score << "\n";
        inorder(node->right);
    }
public:
    BST() {
        root = nullptr;
    }
    void insert(Student s) {
        root = insert(root, s);
    }
    Node* search(string name) {
        return search(root, name);
    }
    void inorder() {
        inorder(root);
    }
};

int main() {
    Student arr[10] = {
        {"Alice", 1, 15},
        {"Bob", 2, 8},
        {"Charlie", 3, 20},
        {"David", 4, 5},
        {"Eve", 5, 12},
        {"Frank", 6, 9},
        {"Grace", 7, 25},
        {"Heidi", 8, 18},
        {"Ivan", 9, 6},
        {"Judy", 10, 30}
    };
    BST tree;
    tree.insert(arr[0]);
    tree.insert(arr[2]);
    tree.insert(arr[4]);
    tree.insert(arr[6]);
    tree.insert(arr[1]);
    tree.insert(arr[3]);
    tree.insert(arr[5]);
    cout << "Initial BST:\n";
    tree.inorder();
    string name;
    cout << "\nEnter student name to search: ";
    cin >> name;
    Node* found = tree.search(name);
    if (found) {
        cout << "Found " << name << " with roll " << found->data.roll
             << " and score " << found->data.score << "\n";
    } else {
        int roll, score;
        cout << name << " not found. Enter roll and score to insert: ";
        cin >> roll >> score;
        tree.insert(Student(name, roll, score));
        cout << "\nUpdated BST:\n";
        tree.inorder();
    }
}
