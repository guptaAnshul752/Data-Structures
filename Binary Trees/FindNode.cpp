// Check whether a node is present or not in a given Binary Tree

#include <iostream>
#include <queue>

using namespace std;

template <typename T>

// Binary TreeNode Class
class BinaryTreeNode{

    public:
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        // Constructor
        BinaryTreeNode(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
        }

        // Destructor
        // First deletes the child den root

        ~BinaryTreeNode(){
        delete left;
        delete right;
        }
};


// TakeInput Function
BinaryTreeNode<int>* takeInputLevelWise(){

    // For root;
    int rootdata;
    cout << "Enter Root Data: ";
    cin >> rootdata;

    // -1 represents NULL node
    // Not necessarily needed
    if (rootdata == -1){
        return NULL;
    }

    // RootNode Created
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0){

        // Creating a Front Node
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        // Left Child
        int LeftData;
        cout << "Enter the left Child of " << front -> data << ": ";
        cin >> LeftData;

        if (LeftData != -1){

        BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(LeftData);
        front->left = leftChild;
        pendingNodes.push(leftChild);

        }
        // Right Child
        int RightData;
        cout << "Enter the right Child of " << front -> data << ": ";
        cin >> RightData;

        if (RightData != -1){

        BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(RightData);
        front->right = rightChild;
        pendingNodes.push(rightChild);
        }
    }
        return root;
}

// isNodePresent Function
bool isNodePresent(BinaryTreeNode<int>* root, int x) {

    // Base Condition
    if (root == NULL){
        return 0;
    }
    // If RootData is Found
    if (root->data == x) {
        return true;
    }

    bool ans = false;

    // Check on Left Subtree
    if (root->left != NULL){
        bool temp=isNodePresent(root->left,x);

        if (ans==false && temp==true){
            ans=true;
        }
    }
    // Check on Right Subtree
    if(root->right!=NULL){

        bool temp=isNodePresent(root->right,x);

        if(ans==false && temp==true) {
            ans=true;
        }
    }
    return ans;
}

int main() {

    // Taking Input Tree
    BinaryTreeNode<int>* root = takeInputLevelWise();
    int x;
    cout << "Enter the Data to be Found: ";
    cin >> x;
    cout << "Is Node " << x << " Present: ";
    if(isNodePresent(root, x)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}
