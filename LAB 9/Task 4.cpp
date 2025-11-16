/*
Step 1: Initial AVL Tree
After inserting 10, 5, 15, 3, 7, the tree looks like this:
       10
      /  \
     5    15
    / \
   3   7
Heights:
Node 3 → 1
Node 7 → 1
Node 5 → 1 + max(1,1) = 2
Node 15 → 1
Node 10 → 1 + max(2,1) = 3
Balance factors (BF = height(left) - height(right)):
Node 3 → 0
Node 7 → 0
Node 5 → 1 - 1 = 0
Node 15 → 0
Node 10 → 2 - 1 = 1  
Balanced

Step 2: Insert 12
12 < 10 → go right
12 < 15 → go left
Insert 12 as left child of 15
Tree now:
       10
      /  \
     5    15
    / \   /
   3   7 12
Heights:
Node 3 → 1
Node 7 → 1
Node 5 → 2
Node 12 → 1
Node 15 → 1 + max(1,0) = 2
Node 10 → 1 + max(2,2) = 3
Balance factors:
Node 3 → 0
Node 7 → 0
Node 5 → 0
Node 12 → 0
Node 15 → 1
Node 10 → 2 - 2 = 0 
Balanced
The tree is still balanced, no rotations needed.
Step 3: Height of Tree
Height = 3 (root 10)

Step 4: Rotations
No rotations needed in this case because all nodes have balance factor -1, 0, or 1.

Step 5: Final AVL Tree
       10
      /  \
     5    15
    / \   /
   3   7 12
Heights:
Node 3 → 1
Node 7 → 1
Node 5 → 2
Node 12 → 1
Node 15 → 2
Node 10 → 3
Balance factors:
Node 3 → 0
Node 7 → 0
Node 5 → 0
Node 12 → 0
Node 15 → 1
Node 10 → 0
Tree is balanced.
*/
