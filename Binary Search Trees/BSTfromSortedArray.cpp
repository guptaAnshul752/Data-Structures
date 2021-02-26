// Binary Search Tree
// Construct BST from a given Sorted Array

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

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

// Construct Tree
BinaryTreeNode<int>* Arr2BST(int *arr, int n) {
    int left = (n-1)/2; // Denotes middle element
    int right = n-left-1;
    if(n==0)
        return NULL;
    if(n==1){
        BinaryTreeNode<int>*root = new BinaryTreeNode<int>(arr[left]);
        return root;
    }

    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(arr[left]);
    BinaryTreeNode<int>* leftAns = Arr2BST(arr, left);           // (Start,Mid)
    BinaryTreeNode<int>* rightAns = Arr2BST(arr+left + 1,right); // (Mid+1,End)
    root->left=leftAns;
    root->right=rightAns;
    return root;
}

int main()
{
    // Sorted Array
    int n;
    cout <<"Enter Size of Array: ";
    cin >> n;
    int *arr = new int[1+n];

    // Taking Input Elements
    cout << "Enter Elements in Sorted Manner:";

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "BST from given Sorted Array is: "<<endl;
    BinaryTreeNode<int>* root = Arr2BST(arr,n);
    printTree(root);
    cout << endl;
    preOrder(root);
    // Delete tree
    delete root;
}
