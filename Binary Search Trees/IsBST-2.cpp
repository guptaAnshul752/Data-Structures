// Binary Search Tree
// Check if given Tree is BST or Not - 2
// Improved Time Complexity -- O(n)

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

// Creating a class
class IsBSTReturn{
    public:
    bool IsBST;
    int minimum;
    int maximum;
};

// Creating a function of type class ISBSTReturn which returns 3 things i.e IsBST,maximum and minimum
IsBSTReturn IsBST2(BinaryTreeNode<int>* root)
{
    if (root == NULL){
        // Creating Object
        IsBSTReturn out;
        // Initializing
        out.IsBST = true;
        out.minimum = INT_MAX;
        out.maximum = INT_MIN;
        return out;
    }

    IsBSTReturn leftOutput = IsBST2(root->left);
    IsBSTReturn rightOutput= IsBST2(root->right);

    IsBSTReturn output;
    output.minimum = min(root->data , min(leftOutput.minimum , rightOutput.minimum));
    output.maximum = max(root->data , max(leftOutput.maximum , rightOutput.maximum));
    output.IsBST = (root->data > leftOutput.maximum) && (root->data < rightOutput.minimum) && leftOutput.IsBST && rightOutput.IsBST;

    return output;
}

bool isBST(BinaryTreeNode<int> *root){
    IsBSTReturn output = IsBST2(root);
    return output.IsBST;
}

// Input tree
// IN-1 : 15 5 20 1 6 16 22 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    // Taking Input
    BinaryTreeNode<int>* root = takeInput();

    cout << endl;
    // Printing tree
    printTree(root);

    // Checking IsBST
    cout << "Is given Tree is a BST? " << isBST(root);

    // Delete tree
    delete root;
    
}
