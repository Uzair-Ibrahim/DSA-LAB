#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int score;
    Student() {}
    Student(string n,int r,int s){
      name=n;
      roll=r;
      score=s;
    }
};

class Node {
public:
    Student data;
    Node* left;
    Node* right;
    Node(Student s){
      data=s;
      left=right=nullptr;
    }
};

class BST {
private:
    Node* root;
    Node* insert(Node* node, Student s) {
        if(!node) return new Node(s);
        if(s.name < node->data.name) node->left=insert(node->left,s);
        else if(s.name > node->data.name) node->right=insert(node->right,s);
        return node;
    }
    Node* search(Node* node,string name) {
        if(!node || node->data.name==name) return node;
        if(name < node->data.name) return search(node->left,name);
        return search(node->right,name);
    }
    Node* minValueNode(Node* node) {
        Node* current=node;
        while(current && current->left) current=current->left;
        return current;
    }
    Node* deleteNode(Node* node,string name) {
        if(!node) return nullptr;
        if(name<node->data.name) node->left=deleteNode(node->left,name);
        else if(name>node->data.name) node->right=deleteNode(node->right,name);
        else {
            if(!node->left){Node* temp=node->right;delete node;return temp;}
            else if(!node->right){Node* temp=node->left;delete node;return temp;}
            Node* temp=minValueNode(node->right);
            node->data=temp->data;
            node->right=deleteNode(node->right,temp->data.name);
        }
        return node;
    }
    Node* deleteLowScore(Node* node) {
        if(!node) return nullptr;
        node->left=deleteLowScore(node->left);
        node->right=deleteLowScore(node->right);
        if(node->data.score<10){
            if(!node->left){
              Node* temp=node->right;
              delete node;
              return temp;
            }
            else if(!node->right){
              Node* temp=node->left;
              delete node;
              return temp;
            }
            Node* temp=minValueNode(node->right);
            node->data=temp->data;
            node->right=deleteNode(node->right,temp->data.name);
        }
        return node;
    }
    void inorder(Node* node) {
        if(!node) return;
        inorder(node->left);
        cout<<node->data.name<<" "<<node->data.roll<<" "<<node->data.score<<"\n";
        inorder(node->right);
    }
    Student maxScore(Node* node) {
        if(!node) return Student("",0,-1);
        Student left=maxScore(node->left);
        Student right=maxScore(node->right);
        Student curr=node->data;
        if(left.score>curr.score) curr=left;
        if(right.score>curr.score) curr=right;
        return curr;
    }
public:
    BST(){
      root=nullptr;
    }
    void insert(Student s){
      root=insert(root,s);
    }
    Node* search(string name){
      return search(root,name);
    }
    void deleteLowScore(){
      root=deleteLowScore(root);
    }
    void inorder(){
      inorder(root);
    }
    Student maxScore(){
      return maxScore(root);
    }
};

int main() {
    Student arr[10]={{"Alice",1,15},{"Bob",2,8},{"Charlie",3,20},{"David",4,5},{"Eve",5,12},{"Frank",6,9},{"Grace",7,25},{"Heidi",8,18},{"Ivan",9,6},{"Judy",10,30}};
    BST tree;
    tree.insert(arr[0]);
    tree.insert(arr[2]);
    tree.insert(arr[4]);  
    tree.insert(arr[6]);
    tree.insert(arr[1]);
    tree.insert(arr[3]);
    tree.insert(arr[5]);
    cout<<"Inorder BST:\n";
    tree.inorder();
    string name="Eve";
    Node* found=tree.search(name);
    if(found) cout<<"\nFound "<<name<<" with score "<<found->data.score<<"\n";
    else cout<<"\n"<<name<<" not found\n";
    tree.deleteLowScore();
    cout<<"\nAfter deleting score<10:\n";
    tree.inorder();
    Student maxS=tree.maxScore();
    cout<<"\nStudent with max score: "<<maxS.name<<" "<<maxS.score<<"\n";
}
