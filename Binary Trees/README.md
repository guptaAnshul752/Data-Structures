## Binary Tree Data Structure

A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children, we typically name them the left and right child. Unlike the linked list, each node stores the address of multiple nodes. Every node stores address of its children and the very first node’s address will be stored in a separate pointer called root.

A Binary Tree node contains following parts.

     1. Data

     2. Pointer to left child
     
     3. Pointer to right child
 
## Properties of Binary Trees: 

- At each level of i, the maximum number of nodes is 2i.

- The height of the tree is defined as the longest path from the root node to the leaf node. The tree which is shown above has a height equal to 3. Therefore, the maximum number of nodes at height 3 is equal to (1+2+4+8) = 15. In general, the maximum number of nodes possible at height h is (20 + 21 + 22+….2h) = 2h+1 -1.

- The minimum number of nodes possible at height h is equal to h+1.

- If the number of nodes is minimum, then the height of the tree would be maximum. Conversely, if the number of nodes is maximum, then the height of the tree would be minimum.

## Height 

If there are 'n' number of nodes in the binary tree.

The minimum height can be computed as:

As we know that,

n = 2h+1 -1

n+1 = 2h+1

Taking log on both the sides,

log2(n+1) = log2(2h+1)

log2(n+1) = h+1

h = log2(n+1) - 1

The maximum height can be computed as:

As we know that,

n = h+1

#### h= n-1

## Types of Binary Tree

There are four types of Binary tree:

- Full/ proper/ strict Binary tree

- Complete Binary tree

- Perfect Binary tree

- Degenerate Binary tree

- Balanced Binary tree


