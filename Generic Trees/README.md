## Generic Trees(N-array Trees)

Generic trees are a collection of nodes where each node is a data structure that consists of records and a list of references to its children(duplicate references are not allowed). Unlike the linked list, each node stores the address of multiple nodes. Every node stores address of its children and the very first node’s address will be stored in a separate pointer called root.

The Generic trees are the N-ary trees which have the following properties: 

     1. Many children at every node.

     2. The number of nodes for each node is not known in advance.
 
#### Simple Approach: 

For storing the address of children in a node we can use an array or linked list. But we will face some issues with both of them.

- In Linked list, we can not randomly access any child’s address. So it will be expensive.
- In array, we can randomly access the address of any child, but we can store only fixed number of children’s addresses in it.

### Better Approach:

We can use Dynamic Arrays (Vectors) for storing the address of children’s address. We can randomly access any child’s address and the size of the vector is also not fixed.
