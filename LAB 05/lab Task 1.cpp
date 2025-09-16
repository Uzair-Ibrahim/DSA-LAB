
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int d;
    Node* n;
    Node(int v) {
        d = v;
        n = NULL;
    }
};

class List {
    Node* h;
    Node* t;
    void print_rev(Node* c) {
        if (c == NULL) return;
        print_rev(c->n);
        cout << c->d << " ";
    }
public:
    List() {
        h = t = NULL;
    }

    void push_back(int v) {
        Node* nn = new Node(v);
        if (h == NULL) {
            h = t = nn;
            return;
        }
        t->n = nn;
        t = nn;
    }

    void push_front(int v) {
        Node* nn = new Node(v);
        if (h == NULL) {
            h = t = nn;
            return;
        }
        nn->n = h;
        h = nn;
    }

    void show_rev() {
        print_rev(h);
        cout << endl;
    }
};

int a[10][10], sol[10][10];
int N = 4, M = 4;
int tx = 2, ty = 0;

bool safe(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M && a[x][y] == 1 && sol[x][y] == 0) return true;
    return false;
}

bool solve(int x, int y) {
    if (x == tx && y == ty) {
        sol[x][y] = 1;
        return true;
    }
    if (safe(x,y)) {
        sol[x][y] = 1;
        if (solve(x+1,y)) return true;
        if (solve(x,y+1)) return true;
        if (solve(x-1,y)) return true;
        if (solve(x,y-1)) return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    List ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_front(5);
    cout << "Linked list in reverse: ";
    ll.show_rev();
    int in[4][4]={{1,1,1,1},{0,0,0,1},{1,1,0,1},{1,1,1,1}};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            a[i][j]=in[i][j];
            sol[i][j]=0;
        }
    }
    cout << "Maze path solution:" << endl;
    if(solve(0,0)){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    } else {
        cout<<"NoPath"<<endl;
    }
    return 0;
}
