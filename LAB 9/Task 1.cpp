/*
-> Why AVL?
-->AVL trees keep the BST height balanced using rotations so search, insert, and delete operations always run in O(log n) time.
   They prevent worst-case skewed trees, improving efficiency and stability compared to normal BSTs.
*/

// Function for AVL

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL {
public:

    int h(Node* n) {
        return n ? n->height : 0;
    }

    int balance(Node* n) {
        return n ? h(n->left) - h(n->right) : 0;
    }

    Node* update(Node* n) {
        n->height = 1 + std::max(h(n->left), h(n->right));
        return n;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        update(y);
        update(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        update(x);
        update(y);
        return y;
    }
};


/*
AVL dry run

BST A:
        10
       /
      6
     / \
    4   8
Balance Factor:
BF(10) = +2 → LL case → Right Rotate
*/

//CONVERSION

class ConvertA : public AVL {
public:
    Node* convert() {
        Node* A4 = new Node(4);
        Node* A8 = new Node(8);
        Node* A6 = new Node(6);
        Node* A10 = new Node(10);

        A6->left = A4;
        A6->right = A8;
        A6->height = 2;

        A10->left = A6;
        A10->height = 3;

        if (balance(A10) == 2 && balance(A6) >= 0)
            return rightRotate(A10);

        return A10;
    }
};


/*
FINAL BST A-->AVL
       6
     /   \
    4     10
            \
             8
*/

/*
BST B:
        10
          \
          16
         /  \
       12   18
Balance Factor:
BF(10) = −2 → RR case → Left Rotate
*/

class ConvertB : public AVL {
public:
    Node* convert() {
        Node* B12 = new Node(12);
        Node* B18 = new Node(18);
        Node* B16 = new Node(16);
        Node* B10 = new Node(10);

        B16->left = B12;
        B16->right = B18;
        B16->height = 2;

        B10->right = B16;
        B10->height = 3;

        if (balance(B10) == -2 && balance(B16) <= 0)
            return leftRotate(B10);

        return B10;
    }
};


/*
Final AVL of B

        16
       /   \
     10     18
       \
        12
*/
