// Binary Tree
// Given a Node, Find its path from root Node ,i.e Return all nodes in between root and target node.

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

// Find Path
vector<int>* FindPath(BinaryTreeNode<int>* root, int data ){

    if (root == NULL){
        return NULL;
    }

    if (root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftoutput = FindPath(root->left,data);
    if (leftoutput != NULL){
        leftoutput->push_back(root->data);
        return leftoutput;
    }
    vector<int>* rightoutput = FindPath(root->right,data);
    if (rightoutput != NULL){
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    else{
        return NULL;
    }
}

// Input Tree
// 9 5 10 1 6 9 12 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    // Node created
    BinaryTreeNode<int>* root = takeInput();
    cout << endl;
    int data;
    cout << "Enter the data ";
    cin >> data;

    vector<int>* output = FindPath(root,data);
    // Printing Elements
    if(output != NULL) {
        for(int i = 0; i < output -> size(); i++) {
            cout << output -> at(i) << endl;
        }
    }
    delete output;
    delete root;
}
