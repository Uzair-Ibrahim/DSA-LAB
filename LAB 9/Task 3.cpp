#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int Value;
    int Height;
    Node* Left;
    Node* Right;
    Node(int val) {
        Value = val;
        Height = 1;
        Left = Right = NULL;
    }
};

class AVL {
    Node* Root;

    int Height(Node* node) { 
        return node ? node->Height : 0; 
    }

    int Balance(Node* node) { 
        return node ? Height(node->Left) - Height(node->Right) : 0; 
    }

    void UpdateHeight(Node* node) {
        int lh = Height(node->Left);
        int rh = Height(node->Right);
        node->Height = 1 + (lh > rh ? lh : rh);
    }

    Node* RotateRight(Node* y) {
        Node* x = y->Left;
        Node* t = x->Right;
        x->Right = y;
        y->Left = t;
        UpdateHeight(y);
        UpdateHeight(x);
        return x;
    }

    Node* RotateLeft(Node* x) {
        Node* y = x->Right;
        Node* t = y->Left;
        y->Left = x;
        x->Right = t;
        UpdateHeight(x);
        UpdateHeight(y);
        return y;
    }

    Node* BalanceNode(Node* node) {
        int b = Balance(node);

        if (b > 1 && Balance(node->Left) >= 0) return RotateRight(node);         // LL
        if (b > 1 && Balance(node->Left) < 0) { 
            node->Left = RotateLeft(node->Left); 
            return RotateRight(node); 
        } // LR
        if (b < -1 && Balance(node->Right) <= 0) return RotateLeft(node);        // RR
        if (b < -1 && Balance(node->Right) > 0) { 
            node->Right = RotateRight(node->Right); 
            return RotateLeft(node); 
        } // RL

        return node;
    }

    Node* InsertNode(Node* node, int val) {
        if (!node) return new Node(val);

        if (val < node->Value) node->Left = InsertNode(node->Left, val);
        else if (val > node->Value) node->Right = InsertNode(node->Right, val);
        else return node;

        UpdateHeight(node);
        return BalanceNode(node);
    }

    void InOrder(Node* node) {
        if (!node) return;
        InOrder(node->Left);
        cout << node->Value << " ";
        InOrder(node->Right);
    }

public:
    AVL() { Root = NULL; }

    void Insert(int val) { Root = InsertNode(Root, val); }

    void Display() { InOrder(Root); cout << endl; }

    void LeftRotateRoot() { Root = RotateLeft(Root); }
};

int main() {
    AVL tree;

    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
    tree.Insert(55); 

    tree.LeftRotateRoot(); // Perform left rotation on root

    cout << "AVL tree after inserting 55 and left rotation on root (inorder): ";
    tree.Display();
}
