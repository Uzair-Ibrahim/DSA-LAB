#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }
    void insert(int val) {
        root = insert(root, val);
    }
    Node* search(Node* node, int val) {
        if (node == nullptr || node->data == val)
            return node;
        if (val < node->data)
            return search(node->left, val);
        return search(node->right, val);
    }
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr)
            return node;
        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }
    void deleteValue(int val) {
        root = deleteNode(root, val);
    }
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
    void inorderTraversal() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
    void preorderTraversal() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }
    void postorderTraversal() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    cout << "Binary Search Tree Created.\n";
    tree.inorderTraversal();
    tree.preorderTraversal();
    tree.postorderTraversal();
    int key = 40;
    if (tree.search(tree.root, key))
        cout << "Element " << key << " found in the tree." << endl;
    else
        cout << "Element " << key << " not found in the tree." << endl;
    cout << "Deleting 20...\n";
    tree.deleteValue(20);
    tree.inorderTraversal();
    cout << "Deleting 30...\n";
    tree.deleteValue(30);
    tree.inorderTraversal();
    cout << "Deleting 50...\n";
    tree.deleteValue(50);
    tree.inorderTraversal();
    return 0;
}
