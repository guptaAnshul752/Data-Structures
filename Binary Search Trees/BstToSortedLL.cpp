// Binary Search Tree
// Construct Linked List from a given BST

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>

// BinaryTreeNode Class
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

    // Constructor
    BinaryTreeNode(T data){
    this -> data = data;
    left = NULL;
    right = NULL;
    }

    // Destructor
    ~BinaryTreeNode(){
    delete left;
    delete right;
    }
};

template<typename T>
// Node Class
class Node{
   public:
   T data;
   Node *next;

   // Creating a constructor

   Node(T data)
   {
       this -> data = data;
       next = NULL;
   }
};

// Take Input Function
BinaryTreeNode<int>* takeInput(){

    // For root;
    int rootData;
    cout << "Enter Data in Root: ";
    cin >> rootData;

    // -1 represents NULL node
    // Not necessarily needed
    if (rootData == -1){
        return NULL;
    }

    // Creating root node
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){

        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        // Left child data
        int leftData;
        cout << "Enter the Left Child of " << front->data <<": ";
        cin >> leftData;
        // Left Node
        if (leftData != -1)
        {
        BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
        // Linking left Node
        front->left = leftChild;
        pendingNodes.push(leftChild);
        }
        // Right child data
        int rightData;
        cout << "Enter the Right Child of " << front->data <<" : ";
        cin >> rightData;
        // Right Node
        if (rightData != -1)
        {
        BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
        // Linking left Node
        front->right = rightChild;
        pendingNodes.push(rightChild);
        }
    }

    return root;
}

// Print function
void printTree(BinaryTreeNode<int>* root) {

    queue<BinaryTreeNode<int>*> pending;

    pending.push(root);

    while(pending.size()!=0){


        cout<<pending.front()->data<<":";

        if (pending.front()->left != NULL){
            cout << "L" << pending.front()->left->data << " ";
            pending.push(pending.front()->left);
        }
        if (pending.front()->right != NULL){
            cout << "R" << pending.front()->right->data;
            pending.push(pending.front()->right);
        }

        cout<<endl;

        pending.pop();
        }
}

// Function to print the linked list
void printLL(Node<int>* head)
{
    if (head == NULL) {
        return;
    }
    Node<int>* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node<int>* constructLL(BinaryTreeNode<int>* root) {
    if(root==NULL)
        return NULL;
  
    if(root->left==NULL && root->right==NULL){
        Node<int>* output = new Node<int>(root->data);
        return output;
    }
  
    Node<int>* output = new Node<int>(root->data);
    Node<int>* leftOutput = constructLL(root->left);
    Node<int>* rightOutput = constructLL(root->right);
  
    if(leftOutput!=NULL){
        Node<int>* temp = leftOutput;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=output;
    }
    output->next = rightOutput;
    if(leftOutput==NULL)
        return output;
    return leftOutput;

}

// Input Tree
// 9 5 10 1 6 9 12 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    // Node created
    BinaryTreeNode<int>* root = takeInput();
    cout << endl;
    Node<int>* head = constructLL(root);
    cout << "Linked List is ";
    printLL(head);
}
