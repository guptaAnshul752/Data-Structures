// Binary Search Tree
// Print Elements in a given range

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

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    
    if(root==NULL)
        return;
    if(root->data>k1)
        elementsInRangeK1K2(root->left,k1,k2);
    if(root->data>=k1 && root->data<=k2){

        cout<<root->data<<" ";
    }
    if(root->data<k2)
        elementsInRangeK1K2(root->right,k1,k2);
}

// Input tree
// 9 5 10 1 6 9 12 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    // Taking Input
    BinaryTreeNode<int>* root = takeInput();

    cout << endl;
    // Printing tree
    printTree(root);

    // Printing in Given range
    int k1,k2;
    cout << "Enter Low value: ";
    cin >> k1;
    cout << "Enter High value: ";
    cin >> k2;

    elementsInRangeK1K2(root,k1,k2);

    // Delete tree
    delete root;
}
