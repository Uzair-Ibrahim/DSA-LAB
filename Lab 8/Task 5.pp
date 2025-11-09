#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};
bool isBSTUtil(Node* node, long long low, long long high){
    if(!node) return true;
    if(node->val <= low || node->val >= high) return false;
    return isBSTUtil(node->left, low, node->val) && isBSTUtil(node->right, node->val, high);
}
bool isBST(Node* root){
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    root1->right->right = new Node(5);
    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(20);
    root2->right->left = new Node(9);
    root2->right->right = new Node(25);
    cout << (isBST(root1) ? "Tree1: BST\n" : "Tree1: Not BST\n");
    cout << (isBST(root2) ? "Tree2: BST\n" : "Tree2: Not BST\n");
    return 0;
}
