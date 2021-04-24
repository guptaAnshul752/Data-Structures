// Binary Search Tree
// Check if given Tree is BST or Not -1
// Time Complexity -- O(n*h)

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

// Min Function for Right Side
// RightMin value is INT_MAX(positive infinity)
int minimum(BinaryTreeNode<int>* root){
    if (root == NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

// Max Function for Left Side
// LeftMax value is INT_MIN(negative infinity)
int maximum(BinaryTreeNode<int>* root){
    if (root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool IsBST(BinaryTreeNode<int>* root) {
    if(root==NULL)
        return true;

    // Condition --> root->data > leftMax && root->data < rightMin
    // Finding LeftMax
    int leftMax = maximum(root->left);
    // Finding RightMin
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data < rightMin) && IsBST(root->left) && IsBST(root->right);
    return output;

}

// Input tree
// IN-1 : 9 5 10 1 6 9 12 -1 -1 -1 -1 -1 -1 -1 -1
// IN-2 : 1 3 2 3 4 2 5 6 2 7 8 -1 -1 -1 -1 1 9 -1

int main()
{
    // Taking Input
    BinaryTreeNode<int>* root = takeInput();

    cout << endl;
    // Printing tree
    printTree(root);

    // Checking IsBST
    cout << "Is given Tree is a BST? " << IsBST(root);

    // Delete tree
    delete root;
}
